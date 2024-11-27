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
  Serial.print("________");
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
