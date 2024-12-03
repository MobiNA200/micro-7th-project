## آزمایش شماره 4 : ساخت ماشین حساب به وسیله keypad

در این آزمایش ما یک ماشین حساب ساده که عملیات جمع، تفریق، ضرب و 
تقسیم را با استفاده از ورودی های یک کیپد 4×4 انجام دهد طراحی کرده ایم و نتیجه را از طریق 
سریال مانیتور نمایش میدهیم.

## کد به شرح زیر است :
```c++
#include <Keypad.h>
const byte ROWS = 4; // four rows 
const byte COLS = 4; // four columns
float firstNumber = 0;
float secondNumber = 0;
float result = 0;
bool section = false;
int type = 0;
char hexaKeys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte colPins[ROWS] = {5, 4, 3, 2}; // Pins used for the rows of the keypad
byte rowPins[COLS] = {9, 8, 7, 6}; // Pins used for the columns of the keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
Serial.begin(9600); // Initialise the serial monitor
}
void loop() {
// Read the pushed button
int button = int(customKeypad.getKey()) - 48;
if (0 <= button && button <= 10) {
Serial.print(button);
if (section == false) {
firstNumber = firstNumber * 10 + button;
} else {
secondNumber = secondNumber * 10 + button;
}
} else {
switch (button) {
case 17: //A
section = true;
type = 1;
Serial.print('+');
break;
case 18: /////B
section = true;
type = 2;
Serial.print('-');
break;
case 19: ////C
section = true;
type = 3;
Serial.print('*');
break;
case 20: ////D
section = true;
type = 4;
Serial.print('/');
break;
case -6: ////*
section = false;
type = 0;
Serial.println(' ');
break;
case -13: /////#
Serial.print(" = ");
switch (type) {
case 1:
result = (firstNumber + secondNumber);
break;
case 2:
result = (firstNumber - secondNumber);
break;
case 3:
result = (firstNumber * secondNumber);
break;
case 4:
result = (firstNumber / secondNumber);
break;}
type = 0;
Serial.println(result);
firstNumber = 0;
secondNumber = 0;
section = false;
break;
}
}
}
```
#### شماتیک مدار :
![shematic](/shematic/photos%20of%20shema/7-4.jpg)