## آزمایش شماره 3 : استفاده از جوی استیک و بازر با آردوینو
در این آزمایش اگر محور X مقدار بیش از 1000 داشته باشد، به این معناست که جوی استیک به سمت راست 
حرکت کرده است و یک نوت پخش میشود.

اگر محور Y مقدار کمتر از 200 داشته باشد، به این معناست که جوی استیک به سمت چپ حرکت 
کرده است و ن.ت دیگری پخش میشود.

اگر محور جوی استیک در مرکز باشد نه چپ و نه راست، بازر خاموش 
میشود و صدایی پخش نمیشود.

#### کد به شرح زیر است :
```c++
const int buzzer = 10;
const int sw = 2;
const int x = A0;
const int y = A1;
void setup() {
pinMode(sw , INPUT_PULLUP);
pinMode(buzzer , OUTPUT);
Serial.begin(9600);
}
void loop() {
Serial.print("switch : ");
Serial.print(digitalRead(sw));
Serial.print("\t\t");
Serial.print("VRx : ");
Serial.print(analogRead(x));
Serial.print("\t\t");
Serial.print("VRy : ");
Serial.print(analogRead(y));
Serial.print("________");
delay(500);
if (analogRead(x) > 1000){
Serial.println("right");
tone(buzzer , 1000);
}
if ( analogRead(y) < 200){
Serial.println("left");
tone(buzzer , 1000);
}
else{
Serial.println("center");
noTone(buzzer);
}
}
```
#### شماتیک مدار :

![shematic](/shematic/photos%20of%20shema/7-3.jpg)
![photo](/photos%20of%20projects/20241119_093345.jpg)