int ledPin = 13;                // choose the pin for the LED
int inputPin = 4;               // choose the input pin (for Radar sensor)
int motionState = LOW;          // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(115200);
}
 
void loop() {
  val = digitalRead(inputPin);  // read input value
  
  if (val == HIGH) {  // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    
    if (motionState == LOW) {
      Serial.println("Motion detected!"); // print on output change
      motionState = HIGH;
    }

    delay(5000);
    digitalWrite(ledPin, LOW); // turn LED OFF
    motionState = LOW;
  }
}