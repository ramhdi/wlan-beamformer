class PhaseShifter {
  public:
    PhaseShifter(int, int, int, int);
    void PSbegin();
    void set(float);
    void reset();

  private:
    int _p1;
    int _p2;
    int _p3;
    int _p4;
};

PhaseShifter::PhaseShifter(int p1, int p2, int p3, int p4) {
  _p1 = p1;
  _p2 = p2;
  _p3 = p3;
  _p4 = p4;
}

void PhaseShifter::PSbegin() {
  pinMode(_p1, OUTPUT);
  pinMode(_p2, OUTPUT);
  pinMode(_p3, OUTPUT);
  pinMode(_p4, OUTPUT);
  reset();
}

void PhaseShifter::set(float ang) {
  int state = (int) ang;
  int b1 = state % 2;
  int b2 = (int)(state / 2) % 2;
  int b3 = (int)(state / 4) % 2;
  int b4 = (int)(state / 8) % 2;
  digitalWrite(_p1, b1);
  digitalWrite(_p2, b2);
  digitalWrite(_p3, b3);
  digitalWrite(_p4, b4);
}

void PhaseShifter::reset() {
  digitalWrite(_p1, 0);
  digitalWrite(_p2, 0);
  digitalWrite(_p3, 0);
  digitalWrite(_p4, 0);
}

PhaseShifter PS1(9, 7, 5, 3);
PhaseShifter PS2(17, 15, 13, 11);
PhaseShifter PS3(25, 23, 21, 19);
PhaseShifter PS4(46, 47, 48, 50);

int ps;
int state;

void setup() {
  // put your setup code here, to run once
  PS1.PSbegin();
  PS2.PSbegin();
  PS3.PSbegin();
  PS4.PSbegin();
  Serial.begin(9600);
  Serial.println("All phase shifters are reset");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Which phase shifter?");
  while (Serial.available() == 0) {}
  ps = Serial.parseInt();
  Serial.print("PS = "); Serial.println(ps);

  Serial.println("Insert state");
  while (Serial.available() == 0) {}
  state = Serial.parseInt();
  Serial.print("State = "); Serial.println(state);

  switch (ps) {
    case 1:
      PS1.set(state);
      Serial.print("PS1 set to state "); Serial.println(state);
      break;

    case 2:
      PS2.set(state);
      Serial.print("PS2 set to state "); Serial.println(state);
      break;

    case 3:
      PS3.set(state);
      Serial.print("PS3 set to state "); Serial.println(state);
      break;

    case 4:
      PS4.set(state);
      Serial.print("PS4 set to state "); Serial.println(state);
      break;

    default:
      PS1.reset();
      PS2.reset();
      PS3.reset();
      PS4.reset();
      Serial.println("All phase shifters are reset");
      break;
  }
}
