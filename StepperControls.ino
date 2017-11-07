void Open() {
  digitalWrite(StepA, HIGH); digitalWrite(StepB, LOW); digitalWrite(StepC, LOW); digitalWrite(StepD, HIGH); 
  delay(2);
  digitalWrite(StepA, LOW); digitalWrite(StepB, LOW); digitalWrite(StepC, HIGH); digitalWrite(StepD, HIGH); 
  delay(2); 
  digitalWrite(StepA, LOW);   digitalWrite(StepB, HIGH);  digitalWrite(StepC, HIGH);  digitalWrite(StepD, LOW); 
  delay(2); 
  digitalWrite(StepA, HIGH);   digitalWrite(StepB, HIGH);   digitalWrite(StepC, LOW);   digitalWrite(StepD, LOW); 
  delay(2);
}

void Close() {
  digitalWrite(StepA, HIGH); digitalWrite(StepB, HIGH); digitalWrite(StepC, LOW); digitalWrite(StepD, LOW); 
  delay(2); 
  digitalWrite(StepA, LOW); digitalWrite(StepB, HIGH); digitalWrite(StepC, HIGH); digitalWrite(StepD, LOW);
  delay(2);
  digitalWrite(StepA, LOW); digitalWrite(StepB, LOW); digitalWrite(StepC, HIGH); digitalWrite(StepD, HIGH); 
  delay(2); 
  digitalWrite(StepA, HIGH); digitalWrite(StepB, LOW); digitalWrite(StepC, LOW); digitalWrite(StepD, HIGH); 
  delay(2); 
}


