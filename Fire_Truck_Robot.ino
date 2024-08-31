// Define pins for motor driver inputs and enable pins
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5

// Initialize variables for motor speed and rotation speed
int M1_Speed = 80; //speed of motor 1
int M2_Speed = 80; //speed of motor 2
int LeftRotationSpeed = 250; // Left Rotation Speed
int RightRotationSpeed = 250; // Right Rotation Speed

// Setup function runs once when the Arduino is powered on or reset
void setup() {
  // Set motor driver input pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set motor driver enable pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // Set sensor pins as inputs
  pinMode(A0, INPUT); // initialize Left sensor as an input
  pinMode(A1, INPUT); // initialize Right sensor as an input
}

// Loop function runs repeatedly as long as the Arduino is power on or reset
void loop() {
  // Read sensor values
  int LEFT_SENSOR = digitalRead(A0);
  int RIGHT_SENSOR = digitalRead(A1);

  // If both sensors detect black line, move forward
  if(RIGHT_SENSOR == 0 && LEFT_SENSOR == 0) {
    forward(); // Move forward
  }

  // If right sensor detects black line, turn right
  else if(RIGHT_SENSOR == 0 && LEFT_SENSOR ==1) {
    right(); // Move right
  }

  // If left sensor detects black line, turn left
  else if(RIGHT_SENSOR == 1 && LEFT_SENSOR == 0) {
    left(); // Move left
  }

  // If both snesors detect white space, stop
  else if(RIGHT_SENSOR == 1 && LEFT_SENSOR == 1) {
    Stop(); // Stop
  }
}

// Function to move the robot forward
void forward() {
  digitalWrite(in1, LOW); // Set input 1 of motor driver to LOW
  digitalWrite(in2, HIGH); // Set input 2 of motor driver to HIGH
  digitalWrite(in3, LOW); // Set input 3 of motor driver to LOW
  digitalWrite(in4, HIGH); // Set input 4 of motor driver to HIGH

  // Set motor speeds
  analogWrite(enA, M1_Speed); // Set speed of motor A
  analogWrite(enB, M2_Speed); // Set speed of motor B
}

// Function to move the robot backward
void backward() {
  digitalWrite(in1, HIGH); // Set input 1 of motor driver to HIGH
  digitalWrite(in2, LOW); // Set input 2 of motor driver to LOW
  digitalWrite(in3, HIGH); // Set input 3 of motor driver to HIGH
  digitalWrite(in4, LOW); // Set input 4 of motor driver to LOW

  // Set motor speeds
  analogWrite(enA, M1_Speed); // Set speed of motor A
  analogWrite(enB, M2_Speed); // Set speed of motor B 
}

// function to turn the robot right
void right() {
  digitalWrite(in1, HIGH); // Set input 1 of motor driver to HIGH
  digitalWrite(in2, LOW); // Set input 2 of motor driver to LOW
  digitalWrite(in3, LOW); // Set input 3 of motor driver to LOW
  digitalWrite(in4, HIGH);

    analogWrite(enA, LeftRotationSpeed);
    analogWrite(enB, RightRotationSpeed);
}

// function to turn the robot left
void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

    analogWrite(enA, LeftRotationSpeed);
    analogWrite(enB, RightRotationSpeed);
}
// function to stop the robot at the end of the black line
void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}