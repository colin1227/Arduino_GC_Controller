// 53 to 35 - buttons
// 34 to 16 - visual
#define A 53        // Yellow 34
#define B 52        // Red    33
// Y(Broken smh)    // Orange 
#define X 51        // Brown  32
#define Z 50        // Blue   31
#define CUp 49      // Grey   30
#define CRight 48   // Purple 29
#define CDown 47    // Green  28
#define R 46        // Black  27
#define CLeft 45    // Black  26
#define Up 44       // Green  25
#define Down 43     // Purple 24(X) -> 12(✓)
#define Right 42    // Grey   23(X) -> 11(✓)
#define Left 41     // Blue   22(X) -> 10(✓)
#define start 40    // Brown  21(X) -> 9 (✓)
#define L 39        // Orange 20(X) -> 8 (✓)
// unused BJT #1    // Red
// unused BJT #2    // Yellow

// run
#define HardLeft 38 // Black

// walk
#define SoftLeft 37 // Yellow

// walk
#define SoftRight 36 // Blue

//run
#define HardRight 35 // Orange

int buttons[19] = {A, B, X, Z, Up, Down, Left, Right, CUp, CRight, CDown, CLeft, R, start, L, HardLeft, HardRight, SoftLeft, SoftRight};

void displayPress(int button, int HoL = HIGH) {
  if (button == Down || button == Right || button == Left || button == start || button == L) {
    digitalWrite(button - 31, HoL);
  } else {
    digitalWrite(button - 19, HoL);
  }
}
void buttonPress(int button, int wait = 40) {
  digitalWrite(button, HIGH);
  displayPress(button);
  delay(wait);
  digitalWrite(button, LOW);
  displayPress(button, LOW);
  delay(40);
}

// SSBU training reset
void reset() {
  digitalWrite(L, HIGH);
  digitalWrite(R, HIGH);
  displayPress(L);
  displayPress(R);
  delay(300);
  digitalWrite(A, HIGH);
  displayPress(A);
  delay(100);
  digitalWrite(L, LOW);
  digitalWrite(R, LOW);
  digitalWrite(A, LOW);
  displayPress(L, LOW);
  displayPress(R, LOW);
  displayPress(A, LOW);
  delay(400);
}

void setup() {
  // command light
  pinMode(A1, OUTPUT);

  // button outputs
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(X, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(Z, OUTPUT);
  pinMode(Left, OUTPUT);
  pinMode(Right, OUTPUT);
  pinMode(Up, OUTPUT);
  pinMode(Down, OUTPUT);
  pinMode(CLeft, OUTPUT);
  pinMode(CRight, OUTPUT);
  pinMode(CUp, OUTPUT);
  pinMode(CDown, OUTPUT);
  pinMode(start, OUTPUT);
  pinMode(HardLeft, OUTPUT);
  pinMode(HardRight, OUTPUT);
  pinMode(SoftLeft, OUTPUT);
  pinMode(SoftRight, OUTPUT);

  // display outputs
  pinMode(34, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);

  // the wierd ones
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);

  // better safe then sorry
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(X, LOW);
  digitalWrite(L, LOW);
  digitalWrite(R, LOW);
  digitalWrite(Z, LOW);
  digitalWrite(Left, LOW);
  digitalWrite(Right, LOW);
  digitalWrite(Up, LOW);
  digitalWrite(Down, LOW);
  digitalWrite(CLeft, LOW);
  digitalWrite(CRight, LOW);
  digitalWrite(CUp, LOW);
  digitalWrite(CDown, LOW);
  digitalWrite(start, LOW);
  digitalWrite(HardLeft, LOW);
  digitalWrite(HardRight, LOW);
  digitalWrite(SoftLeft, LOW);
  digitalWrite(SoftRight, LOW);
  pinMode(34, LOW);
  pinMode(33, LOW);
  pinMode(32, LOW);
  pinMode(31, LOW);
  pinMode(30, LOW);
  pinMode(29, LOW);
  pinMode(28, LOW);
  pinMode(27, LOW);
  pinMode(26, LOW);
  pinMode(25, LOW);
  pinMode(12, LOW);
  pinMode(11, LOW);
  pinMode(10, LOW);
  pinMode(9, LOW);
  pinMode(8, LOW);
  pinMode(19, LOW);
  pinMode(18, LOW);
  pinMode(17, LOW);
  pinMode(16, LOW);

  Serial.begin(115200);
  Serial.setTimeout(100);
}

void loop() {
  if(Serial.available() > 0) {
    String readVal = Serial.readString();
    Serial.println(readVal);
    analogWrite(A1, 255);
    if (readVal == "Up400"){
      buttonPress(Up, 400);
    } else if (readVal == "Down400"){
      buttonPress(Down, 400);
    } else if (readVal == "Left400"){
      buttonPress(Left, 400);
    } else if (readVal == "Right400"){
      buttonPress(Right, 400);
    } else if (readVal == "A") {
      buttonPress(A);
    } else if (readVal == "B") {
      buttonPress(B);
    } else if (readVal == "start") {
      buttonPress(start);
    } else if (readVal == "test") {
      for(int r = 0; r < 2; r++) {
        if ( r == 0) {
          for(int i = 0; i < 19;i++) {
            buttonPress(buttons[i], 500);
          }
        } else {
          for(int g = 18; g >= 0;g--) {
            buttonPress(buttons[g], 300);
          }
        }
       delay(500);
      }
    } else if(readVal == "reset") {
      reset();
    }
    analogWrite(A1, 0);
  }
}
