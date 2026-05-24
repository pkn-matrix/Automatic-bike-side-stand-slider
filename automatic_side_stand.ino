#define IN1 9
#define IN2 10
#define LIMIT_SWITCH 2
#define HALL_SENSOR 3

bool moveForwardNext = true;
bool buttonPressed = false;
int hallCount = 0;
bool hallTriggered = false;
bool cooldown = false; // Prevent immediate re-trigger after retraction

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(LIMIT_SWITCH, INPUT_PULLUP);
  pinMode(HALL_SENSOR, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  // --- Limit Switch Operation ---
  if (digitalRead(LIMIT_SWITCH) == LOW) {
    if (!buttonPressed) {
      buttonPressed = true;
      Serial.println("Limit switch activated.");
      if (moveForwardNext) {
        moveForward();
      } else {
        moveBackward();
      }
      delay(1000);
      stopMotor();
      moveForwardNext = !moveForwardNext;
    }
  } else {
    buttonPressed = false;
  }

  // --- Hall Sensor Operation ---
  if (digitalRead(HALL_SENSOR) == LOW) {
    if (!hallTriggered && !cooldown) {
      hallTriggered = true;
      hallCount++;
      Serial.print("Hall sensor count: ");  // Fixed: removed hardcoded "5"
      Serial.println(hallCount);
      delay(50);
    }
  } else {
    hallTriggered = false;
  }

  // Retract stand when speed threshold reached (5 pulses ~ 10 km/h)
  if (hallCount >= 5) {
    Serial.println("Speed threshold reached: Retracting stand.");
    moveBackward();
    delay(1000);
    stopMotor();
    hallCount = 0;
    cooldown = true;      // Block re-trigger
    delay(2000);          // 2 second cooldown
    cooldown = false;     // Resume normal detection
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.println("Motor moving forward.");
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  Serial.println("Motor moving backward.");
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("Motor stopped.");
}
