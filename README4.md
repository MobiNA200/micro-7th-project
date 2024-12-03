## آزمایش شماره 5 : پیاده سازی سیستم قفل رمزدار با استفاده از کیپد و آردوینو

ددر این آزمایش قصد داریم یک سیستم قفل رمزدار با استفاده از کیپد 4×4 طراحی کنیم که کاربر بتواند رمز 
عبور را تعیین کرده و برای دسترسی از آن استفاده کند. در صورت ورود رمز 
صحیح، LEDروشن میشود و در صورت ورود رمز اشتباه، LEDخاموش باقی 
میماند.

#### کد به شرح زیر است :
```c++
#include <Keypad.h>
int led = 13;
float pass = 0;
float firstNumber = 0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte colPins[ROWS] = {5, 4, 3, 2}; // Pins used for the rows of the keypad
byte rowPins[COLS] = {9, 8, 7, 6}; // Pins used for the columns of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
Serial.begin(9600);
pinMode(led , OUTPUT);
Serial.println("set password : ");
for (int i = 0 ; i < 4 ; i++) {
int button = int(customKeypad.getKey()) - 48;
Serial.println(button);
if (0 <= button && button <= 10) {
Serial.print(button);
pass = pass * 10 + button;
} }
Serial.println("set password is copmleted, Enter code:");
}
void loop() {
// Serial.println("enter the password");
int button = int(customKeypad.getKey()) - 48;
if (0 <= button && button <= 10) {
Serial.print(button);
for (int i = 0 ; i < 4 ; i++) {
firstNumber = firstNumber * 10 + button;
}
}
if ( pass == firstNumber) {
digitalWrite(led , HIGH);
}
else {
digitalWrite(led , LOW);
}
firstNumber = 0;
delay(1000);
}
```

#### شماتیک :

![shematic](/shematic/photos%20of%20shema/7-5.jpg)