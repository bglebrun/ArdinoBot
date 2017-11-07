#include "TimerOne.h"

// Digital I/O
const int Trig = 0;
const int Echo = 1;
const int FrontSwitch = 2;
const int LeftWheel = 3;
const int RightWheel = 4;
const int ControlOneA = 5;
const int ControlTwoA = 6;
const int ControlThreeA = 7;
const int ControlFourA = 8;
const int StepD = 9;
const int StepC = 10;
const int StepB = 11;
const int StepA = 12;

// Analog I/O
const int DirectionSwitch = A0; // Yellow - HIGH, Blue - LOW
const int LeftSwitch = A1;
const int RightSwitch = A2;
const int Blue = A3;
const int Red = A4;
const int Green = A5;

enum steps {pushbak, inbound, outbound, completed};

enum followSide {left, right};

unsigned int timeout = 0;

followSide FollowingSide = followSide(left);

steps CurrentStep = steps(pushbak);

void setup() {
  
  // Outputs
  pinMode(Trig, OUTPUT);
  pinMode(LeftWheel, OUTPUT);
  pinMode(RightWheel, OUTPUT);
  pinMode(ControlOneA, OUTPUT);
  pinMode(ControlTwoA, OUTPUT);
  pinMode(ControlThreeA, OUTPUT);
  pinMode(ControlFourA, OUTPUT);
  pinMode(StepD, OUTPUT);
  pinMode(StepC, OUTPUT);
  pinMode(StepB, OUTPUT);
  pinMode(StepA, OUTPUT);

  // Inputs
  pinMode(Echo, INPUT);
  pinMode(DirectionSwitch, INPUT);

  if (digitalRead(DirectionSwitch) == HIGH) {
    // Blue - left
    FollowingSide = followSide(left);
  } else {
    // Yellow - right
    FollowingSide = followSide(right);
  }

  delay(3000);
  digitalWrite(Blue, HIGH);
}

void loop() {
  OpenMaw();
  CloseMaw();
  //StepThrough();
  /*TurnRight90();
  delay(4000);
  TurnLeft90();
  delay(4000);*/
}

void StepThrough() {
  switch(CurrentStep) {
    
    case pushbak:
      Pushbak();
    break;
    
    case inbound:
      Inbound();
    break;
    
    case outbound:
      Outbound();
    break;

    case completed:
      digitalWrite(Red, LOW);
      digitalWrite(Green, LOW);
      digitalWrite(Blue, LOW);
      Stop();
    break;
    
    default:
      // We dun fucked up
    break;
  }
}

void Pushbak() {
  // Pushing Back
  while(getDistance() < 27) {
    Forward();
  }
  
  // Turn
  if (FollowingSide == followSide(left)) {
    while(getDistance() < 100)  TurnRight90();
  } else {
     while(getDistance() < 100) TurnLeft90();
  }
  
  Stop();
  delay(2000);
  // Start inbound
  CurrentStep = steps(inbound);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, HIGH);
}

void Inbound() {
  if ( digitalRead(LeftSwitch) == LOW && digitalRead(RightSwitch) == LOW) {
    if (FollowingSide == followSide(right)) {
      digitalWrite(Blue, HIGH);
      digitalWrite(Green, HIGH);
      RightWheelHalfBwd();
    } else {
      digitalWrite(Blue, HIGH);
      digitalWrite(Green, HIGH);
      LeftWheelHalfBwd();
    }
  } else {
      digitalWrite(Blue, LOW);
      digitalWrite(Green, HIGH);
      Backward();
  }

  if (getDistance() < 15) {
    retrieveCube();
    CurrentStep = steps(outbound);
    digitalWrite(Blue, LOW);
    digitalWrite(Green, LOW);
    digitalWrite(Red, HIGH);
  }
}

void Outbound() {

  if (digitalRead(FrontSwitch) == HIGH) {
    Stop();
    CurrentStep = steps(completed);
  }
      
  if ( digitalRead(LeftSwitch) == LOW && digitalRead(RightSwitch) == LOW) {
    if (FollowingSide == followSide(right)) {
      digitalWrite(Blue, HIGH);
      digitalWrite(Red, HIGH);
      LeftWheelHalfFwd();
    } else {
      digitalWrite(Blue, HIGH);
      digitalWrite(Red, HIGH);
      RightWheelHalfFwd();
    }
  } else {
      digitalWrite(Blue, LOW);
      digitalWrite(Red, HIGH);
      Forward();
  }
}

void retrieveCube() {
  if(FollowingSide == followSide(left)) {
    TurnRight90();
    delay(1300);
  } else {
    TurnLeft90();
    delay(1300);
  }

  Stop();
  OpenMaw();
  
  while(getDistance() < 35) {
    Forward();
  }
  
  delay(500);
  CloseMaw();
  
  while(getDistance() > 2) {
    Backward();
  }

  if (FollowingSide == followSide(left)) {
    TurnRight90();
    delay(1000);
  } else {
    TurnLeft90();
    delay(1000);
  }
}

void OpenMaw() {
  for (int i = 0; i < 48 * 64 / 4; i++) Open();
}

void CloseMaw() {
  for (int i = 0; i < 48 * 64 / 4; i++) Close();
}

long getDistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  return (pulseIn(Echo, HIGH) / 2) / 29.1;
}

