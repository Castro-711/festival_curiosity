void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensor_val = analogRead(A0);
  
  Serial.println(sensor_val);
//  Serial.println("Yo Yo Yo..");

  delay(500);

}
