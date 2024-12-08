## آزمایش شماره 1 : خواندن مقادیر محورهای جوی استیک 

در این آژمایش ما یک جوی استیک در اختیار داریم که با چرخاندن آن میتوانیم مقدار داده شده در سریال مانیتور را مشاهده کنیم.

ماژول جویاستیک دارای سه خروجی اصلی است:

.1 محور VRx  : متصل به یک پین آنالوگ برای اندازهگیری مقدار ولتاژ 
معادل حرکت در محور افقی.

.2 محور VRy : متصل به یک پین آنالوگ برای اندازهگیری مقدار ولتاژ 
معادل حرکت در محور عمودی.

.3 کلید فشاری SW : متصل به یک پین دیجیتال که با فشار دادن جوی استیک 
مقدار آن تغییر می کند.

#### کد ما به شرح زیر است : 
```c++
const int sw = 2;
const int x = A0;
const int y = A1;
void setup() {
pinMode(sw , INPUT_PULLUP);
Serial.begin(9600);}
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
}
```
#### شماتیک مدار :
![shematic](/shematic/photos%20of%20shema/7-1.jpg)

![photo](/photos%20of%20projects/20241119_093433.jpg)


## آزمایش شماره 2 : تشخیص حرکات به راست یا چپ

این آزمایش تنها تفاوتی که دارد با آزمایش قبل دز این است که در سریال مانیتور فقط مقدار نشان نمیدهد و میتواند وقتی جوی استیک را به سمت محور راست گرفتیم کلمه ```right``` و وقتی به سمت محور چپ گرفتیم کلمه ```left``` را نشان دهد و وقتی در وسط قرار داشت کلمه  ```center``` را نشان میدهد.

کد ما به شرح زیر است :
```c++
const int sw = 2;
const int x = A0;
const int y = A1;
void setup() {
 pinMode(sw , INPUT_PULLUP);
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
 delay(500);
 if (analogRead(x) > 1000){
 Serial.println("right");
}
 if ( analogRead(y) < 200){
 Serial.println("left");
 }
 else{
 Serial.println("center");
 }
}
```
#### شماتیک مدار : 
![shematic](./shematic/photos%20of%20shema/7-1.jp)


#### در این گیف نحوه کار را میبینید :

![gif](/videos%20of%20projects/InShot_20241127_184426844-ezgif.com-video-to-gif-converter.gif)
