int tempPin = A0;
float tempValue = 0;

int WLED = 12;
int RLED = 3;

float x = 22.95;

void setup() {
  Serial.begin(9600);
  pinMode(tempPin, INPUT);
  pinMode(WLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  tempValue = analogRead(tempPin);
  tempValue = tempValue * 0.48828125;
  Serial.print("Temperature is ");
  Serial.print(tempValue);
  Serial.print(" °Celsius");
  Serial.println();

  if (tempValue < x)
  {
    digitalWrite(WLED, HIGH);
    delay(50);
    digitalWrite(WLED, LOW);
  }
  else if (tempValue > x)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (tempValue == x)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(WLED, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(WLED, LOW);
  }

  delay(100);
}
