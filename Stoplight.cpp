// C++ code
//
/*
  This program shows a green light until the distance is less
  than 10 where it than turns yellow than red and repeats

  By: Teddy Sannan
*/

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup()
{
  pinMode(13, OUTPUT); // Define Red LED pin
  pinMode(12, OUTPUT); // Define Yellow LED pin
  pinMode(11, OUTPUT); // Define Green LED pin

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop()
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  digitalWrite(11, HIGH); // Turn Green LED On

  if (distance <= 10) { // Check distance if < than 10
    digitalWrite(11, LOW); // Turn Green LED On
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    // turn the LED off by making the voltage LOW
    digitalWrite(12, LOW);

    while (distance <= 10) { // Constantly run and check distance till > 10
      // Clears the trigPin condition
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
      // Displays the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      // turn the LED on (HIGH is the voltage level)
      digitalWrite(13, HIGH);
    }
    digitalWrite(13, LOW); // Turn off LED when loop ends
  }
}