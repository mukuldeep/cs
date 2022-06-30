//Tested on Arduino UNO as sender

char buff[10]="abc def g";//data to send

void setup() {
	Serial.begin(9600);//begining serial communication at boudrate 9600
}

void loop() {
	Serial.write(buff,10);//writing from buff, first 10 chars
	delay(100);//delay 100ms
}
