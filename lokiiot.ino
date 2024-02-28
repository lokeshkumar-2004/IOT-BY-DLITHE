int led =BUILTIN_LED;
void setup() {
  pinMode(led,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,HIGH);
Serial.println("Led ON");
delay(5000);
digitalWrite(led,LOW);
Serial.println("Led OFF");
delay(5000);
}
