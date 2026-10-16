const int buzzerPin = 17;
const int micPin = 34;
const int threshold = 1500;
bool alarmOn = false;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  delay(5000); // delay before alarm starts
  alarmOn = true;
}

void loop() {
  if (alarmOn) {
    digitalWrite(buzzerPin, HIGH);
    delay(700);
    digitalWrite(buzzerPin, LOW);
    delay(300);

    int val = analogRead(micPin);
    Serial.println(val);

    static int count = 0;
    if (val > threshold) {
      count++;
      if (count >= 3) {
        alarmOn = false;
        digitalWrite(buzzerPin, LOW);
        Serial.println("Alarm silenced!");
      }
    } else {
      count = 0;
    }
  }
  delay(50);
}