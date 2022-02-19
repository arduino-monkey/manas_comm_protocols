String str;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  while (Serial.available()){
    str = Serial.readString();
  }
  if (str == "on\n"){
    Serial.println("Sending: 1");
    Serial3.print('1');
  }else{
    Serial.println("Sending: 0");
    Serial3.print('0');
  }
}
