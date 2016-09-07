/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 Pullupp-switch

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.

 This example code is in the public domain.
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
boolean buttonValue = true;   //Current button value
boolean lastButtonValue = true; //Previous button
boolean ledValue = false; //Current led value

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value, write the opposite value to ledPin:
  buttonValue = digitalRead(buttonPin); //Copy button value to the variable
  if (!buttonValue && lastButtonValue != buttonValue) { //Make sure value has changed and that the button is pressed
      ledValue = !ledValue; //Invert ledValue
    }
  lastButtonValue = buttonValue;
  digitalWrite(ledPin, ledValue); //Write the values
delay(20); //Wait fo 20 mS
}
