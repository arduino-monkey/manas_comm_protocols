char str;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  while (Serial3.available()){
    str = Serial3.read();
    Serial.println(str);
  }
  
  if (str == '1'){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
}
