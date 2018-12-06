$(function() { /* Wait for jQuery */

  /* Init vars */
  var isCodeCompiled = false;
  var LocKey = new LocaleKeyboard();
  var Duck = new Duckuino();

  try {
    var isFileSaverSupported = !!new Blob();
  } catch (e) {}

  /* Compile button enable/disable */
  $(".input > textarea").keyup(function() {
    if($(this).val() !== "") {
      $(".process-but button").prop("disabled", false);
      $(".process-but select").prop("disabled", false);
    } else {
      $(".process-but button").prop("disabled", true);
      $(".process-but select").prop("disabled", true);
    }
  });

  /* Compile button click */
  $(".process-but button").click(function() {
      document.getElementById("tag").style.opacity = 1;
      
    var duckyScript = $(".input > textarea").val();
    var selectedModule = $(".process-but select").find(":selected").text();

    if(duckyScript == undefined || duckyScript == '' || duckyScript == 'Enter DuckyScript here'){
        alert('Input is invalid');
    }
      
    /* Load Duckuino & Compile */
    Duck.loadModule(selectedModule);
    var compilerOut = Duck.compileCode(duckyScript);

    /* Check for error */
    if(compilerOut.returnCode === 0) {
      /* Set textarea text */
      $(".export > textarea").val(compilerOut.compiledCode);

      /* Enable buttons */
      $(".dl-but button").prop("disabled", false);
      $(".dl-but select").prop("disabled", false);
      $(".copy-but").prop("disabled", false);
      $(".export .copy-but").text("Copy !");

      /* Show compilation infos */
      $(".process .tooltip > span").text(compilerOut.returnMessage);
      $(".process .tooltip").removeClass("error"); $(".process .tooltip").addClass("info");
      $(".process .tooltip").show();
    } else {
      /* Disable buttons and show compilation error */
      $(".dl-but button").prop("disabled", true);
      $(".dl-but select").prop("disabled", true);
      $(".copy-but").prop("disabled", true);

      /* Compilation error */
      $(".process .tooltip > span").text(compilerOut.returnMessage);
      $(".process .tooltip").removeClass("info"); $(".process .tooltip").addClass("error");
      $(".process .tooltip").show();
    }
  });

  /* List modules*/
  Duck.listModules().forEach(function (moduleName) {
    $(".process-but select").append("<option name=\"" + moduleName + "\">" + moduleName + "</option>");
  });

  /* Download button */
  $(".dl-but button").click(function() {
    var compilerOut = $(".export > textarea").val();
    var filename = $("#filename").val();
      
    
    if(compilerOut == undefined || filename == undefined || compilerOut == '' || filename == '' || compilerOut == 'Error, look at the console...'){
        alert('Payload name or code is empty!');
        return;
    }
    
    if ($(".dl-but select").find(":selected").text() == "Only .ino") {
        $("<a />", {
            download: filename + ".ino",
            href: URL.createObjectURL(
                new Blob([compilerOut], {
                    type: "text/plain"
            }))
        })
        .appendTo("body")[0].click();
        $(window).one("focus", function() {
            $("a").last().remove()
        })
    }
      
    else if ($(".dl-but select").find(":selected").text() == "Sketch: .ino + C files") {
        var zipHandler = new JSZip();
        zipHandler.file(filename + "/" + filename + ".ino", compilerOut);
        
        zipHandler.file("readme", $.ajax({
            url: 'readme.default',
            mimeType: 'text/plain',
            type: 'get',
            success: function(data) {return data;}
        }));
        
        LocKey.setLocale("en_US");

        // Append all to the zip
        zipHandler.file(filename + "/Keyboard.cpp", LocKey.getSource());
        zipHandler.file(filename + "/Keyboard.h", LocKey.getHeader());
        
        // Download
        zipHandler.generateAsync({type:"blob"})
            .then(function(content) {
                saveAs(content, filename + ".zip");
            }
        );
    }
      
  });
    
  $("#clear").click(function() {
      document.getElementById("input").value = "";
      document.getElementById("output").value = "";
      document.getElementById("comp").setAttribute("disabled", true);
      document.getElementById("down").setAttribute("disabled", true);
      document.getElementById("tag").style.opacity = 0;
  });

});