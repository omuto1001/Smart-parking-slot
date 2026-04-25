int trigPin = 5;
int echoPin = 3;
int ledRed = 13;
int ledOrange = 12;
int ledGreen = 11;


long duration;
int distance;
unsigned long occupiedStartTime = 0;
bool wasOccupied = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;
  

  if (distance > 20 || duration == 0) {

    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledOrange, LOW);
    wasOccupied = false;
    occupiedStartTime = 0;
  } 
  else {
  
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    
 
    if (wasOccupied == false) {
      occupiedStartTime = millis();
      wasOccupied = true;
    }
    
   
    if (millis() - occupiedStartTime > 10000) {
      digitalWrite(ledOrange, !digitalRead(ledOrange));
    } 
    else {
      digitalWrite(ledOrange, LOW);
    }
  }
  
  delay(100);
}
