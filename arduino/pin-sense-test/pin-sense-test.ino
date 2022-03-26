int pin = 2; //define interrupt pin to 2
volatile int timer = 0; // To make sure variables shared between an ISR
volatile int timer_ = 0;
//the main program are updated correctly,declare them as volatile.

void setup() {
  Serial.begin(115200);
   pinMode(2, INPUT);//_PULLUP); //set pin 13 as output
   attachInterrupt(digitalPinToInterrupt(pin), blink, FALLING);
   
} 
void loop() {
  noInterrupts();
  digitalWrite(2, LOW);
  delay(1);
  interrupts();
  timer_ = micros();
  digitalWrite(2, HIGH);
  delay(1);
  Serial.println("T: " + String(timer));
} 

void blink() { 
   timer = micros()-timer_;
}
