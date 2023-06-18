#include <Arduino.h>
#include <IRremote.h>

// Define the IR receiver pin
const int receiverPin = 2;

// Define the LED pin
const int ledPin = 13;

// Define the codes for the buttons on your IR remote
const unsigned long button1Code = 0xFFA25D;
const unsigned long button2Code = 0xFF629D;
const unsigned long button3Code = 0xFFE21D;
const unsigned long button4Code = 0xFF22DD;

IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initialize the IR receiver
  irrecv.enableIRIn();
  serial.begin(9600)
}

void loop() {
  if (irrecv.decode(&results)) {
    // Check if the received code matches any of the button codes
    switch (results.value) {
      case button1Code:
        // Turn on the LED
        digitalWrite(ledPin, HIGH);
        break;

      case button2Code:
        // Turn off the LED
        digitalWrite(ledPin, LOW);
        break;

      case button3Code:
        // Toggle the LED state
        digitalWrite(ledPin, !digitalRead(ledPin));
        break;

      case button4Code:
        // Blink the LED three times
        for (int i = 0; i < 3; i++) {
          digitalWrite(ledPin, HIGH);
          delay(200);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
        break;
    }

    irrecv.resume();  // Receive the next value
  }
}
