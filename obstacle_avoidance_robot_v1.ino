#include <AFMotor.h>

// motor objects
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Ultrasonic sensor pins
#define TRIG A0
#define ECHO A1

int threshold = 30; 
int speedM = 150; 


void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  motor1.setSpeed(speedM);
  motor2.setSpeed(speedM);
  motor3.setSpeed(speedM);
  motor4.setSpeed(speedM);

  stopMotors();
}


void loop() {
  long dist = getDistance();

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist < threshold) {
    stopMotors();
    delay(100);

    moveBackward();
    delay(300);

    stopMotors();
    delay(100);

    turnLeft();
    delay(400);

    stopMotors();
    delay(100);
  } 
  else {
    moveForward();
  }
}


long getDistance() {
  // Trigger pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000); 
  long distance = duration * 0.034 / 2; // convert to cm

  return distance;
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}