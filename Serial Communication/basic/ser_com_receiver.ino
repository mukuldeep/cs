//Tested on ESP8266 / NODE MCU 0.9 as receiver

void setup() {
  Serial.begin(9600);//begining serial communication at boudrate 9600
}

void loop() {
  if(Serial.available()>0){//when Serial is ready
    Serial.println(char(Serial.read()));//reading single char and printing in serial monitor    
  }
}
