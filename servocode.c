#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Password.h>
#define BUZZER 11 // (unused, keep if you want a beep later)
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Password is 4 digits
Password password = Password(“1111”);
Const byte PASSWORD_LENGTH = 4;
Byte currentPasswordLength = 0;

Const byte startMaskCol = 5; // where stars begin
// Keypad setup
Const byte ROWS = 4;
Const byte COLS = 4;
Char keys[ROWS][COLS] = {
{‘D’, ‘C’, ‘B’, ‘A’},
{‘#’, ‘9’, ‘6’, ‘3’},
{‘0’, ‘8’, ‘5’, ‘2’},
{‘*’, ‘7’, ‘4’, ‘1’},
};
Byte rowPins[ROWS] = {2, 3, 4, 5};
Byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Void setup() {
Servo.attach(10);
Servo.write(50); // locked position
Lcd.init();
Lcd.backlight();
Lcd.setCursor(3, 0);
Lcd.print(“WELCOME TO”);
Lcd.setCursor(0, 1);
Lcd.print(“DOOR LOCK SYSTEM”);
Delay(2000);
Lcd.clear();
showPrompt();
}
Void loop() {
Char key = keypad.getKey();
If (key == NO_KEY) return;
Delay(60); // simple debounce
If (key == ‘C’) {

resetInput();
return;
}
// Only process digits 0-9
If (key >= ‘0’ && key <= ‘9’) {
// mask input
Lcd.setCursor(startMaskCol + currentPasswordLength, 1);
Lcd.print(“*”);
Password.append(key);
currentPasswordLength++;
if (currentPasswordLength == PASSWORD_LENGTH) {
// evaluate once
If (password.evaluate()) {
unlockDoor();
} else {
showError();
}
resetInput();
}
}
}
Void showPrompt() {
Lcd.setCursor(1, 0);
Lcd.print(“ENTER PASSWORD”);
Lcd.setCursor(startMaskCol, 1);
}
Void resetInput() {
Password.reset();
currentPasswordLength = 0;
lcd.clear();
showPrompt();
}
6
Void unlockDoor() {
Servo.write(110); // unlocked
Lcd.clear();
Lcd.setCursor(0, 0);
Lcd.print(“CORRECT PASSWORD”);
Lcd.setCursor(0, 1);
Lcd.print(“DOOR UNLOCKED”);
Delay(5000);
// optionally keep door unlocked or re-lock after delay:
Servo.write(50); // auto re-lock
}
Void showError() {
Lcd.clear();
Lcd.setCursor(0, 0);
Lcd.print(“WRONG PASSWORD!”);
Lcd.setCursor(0, 1);
Lcd.print(“TRY AGAIN”);
Delay(2000);
}
