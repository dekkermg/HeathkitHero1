int ledPin = 13;
int inputPin = 22;
int pirState = LOW;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (pirState == LOW) {
      // we have just turned on
      // Serial.printLn("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); //turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      // Serial.printLn("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;   
    }
  } 
}
