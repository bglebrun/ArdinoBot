void Stop() {
  StopLeftWheel();
  StopRightWheel();
}

void Forward() {
  LeftWheelForward();
  RightWheelForward();
}

void Backward() {
  LeftWheelBackward();
  RightWheelBackward();
}

void StopLeftWheel() {
  enableLeft();
  digitalWrite(ControlTwoA, LOW);
  digitalWrite(ControlOneA, LOW);
}

void StopRightWheel() {
  enableRight();
  digitalWrite(ControlThreeA, LOW);
  digitalWrite(ControlFourA, LOW);
}

void enableLeft() {
  analogWrite(LeftWheel, HIGH);
}

void disableLeft() {
  digitalWrite(LeftWheel, LOW);
}

void enableRight() {
  analogWrite(RightWheel, HIGH);
}

void disableRight() {
  digitalWrite(RightWheel, LOW);
}


void LeftWheelHalfFwd() {
  analogWrite(LeftWheel, HIGH);
  digitalWrite(ControlTwoA, HIGH);
  digitalWrite(ControlOneA, LOW);
}

void RightWheelHalfFwd() {
  analogWrite(RightWheel, HIGH);
  digitalWrite(ControlThreeA, LOW);
  digitalWrite(ControlFourA, HIGH);
}

void LeftWheelHalfBwd() {
  analogWrite(LeftWheel, HIGH);
  digitalWrite(ControlTwoA, LOW);
  digitalWrite(ControlOneA, HIGH);
}

void RightWheelHalfBwd() {
  analogWrite(RightWheel, HIGH);
  digitalWrite(ControlThreeA, HIGH);
  digitalWrite(ControlFourA, LOW);
}

void LeftWheelForward() {
  enableLeft();
  digitalWrite(ControlTwoA, HIGH);
  digitalWrite(ControlOneA, LOW);
}

void LeftWheelBackward() {
  enableLeft();
  digitalWrite(ControlTwoA, LOW);
  digitalWrite(ControlOneA, HIGH);
}

void RightWheelForward() {
  enableRight();
  digitalWrite(ControlThreeA, LOW);
  digitalWrite(ControlFourA, HIGH);
}

void RightWheelBackward() {
  enableRight();
  digitalWrite(ControlThreeA, HIGH);
  digitalWrite(ControlFourA, LOW);
}

