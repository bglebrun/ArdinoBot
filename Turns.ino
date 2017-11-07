void TurnLeft180() {
  LeftWheelForward();
  RightWheelBackward();
  delay(1400);
  StopLeftWheel();
  StopRightWheel();
}

void TurnRight180() {
  RightWheelForward();
  LeftWheelBackward();
  delay(1400);
  StopRightWheel();
  StopLeftWheel();
}

void TurnLeft90() {
  LeftWheelForward();
  RightWheelBackward();
  delay(1200);
  StopLeftWheel();
  StopRightWheel();
}

void TurnRight90() {
  RightWheelForward();
  LeftWheelBackward();
  delay(1200);
  StopRightWheel();
  StopLeftWheel();
}

void WideLeft() {
  StopRightWheel();
  LeftWheelForward();
}

void WideRight() {
  StopLeftWheel();
  RightWheelForward();
}

void InPlaceLeft() {
  LeftWheelForward();
  RightWheelBackward();
}

void InPlaceRight() {
  RightWheelForward();
  LeftWheelBackward();
}

