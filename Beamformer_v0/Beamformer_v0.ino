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
  int state = (int) ang / 22.5;
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
int state;

void setup() {
  // put your setup code here, to run once
  PS1.PSbegin();
  PS2.PSbegin();
  PS3.PSbegin();
  PS4.PSbegin();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0) {}
  state = Serial.parseInt();

  Serial.print("State = "); Serial.println(state);

  switch (state) {
    case 0:
      PS1.reset();
      PS2.reset();
      PS3.reset();
      PS4.reset();
      break;

    case 1:
      PS1.set(337.5);
      PS2.set(225);
      PS3.set(135);
      PS4.set(22.5);
      break;

    case 2:
      PS1.set(315);
      PS2.set(225);
      PS3.set(135);
      PS4.set(45);
      break;

    case 3:
      PS1.set(292.5);
      PS2.set(225);
      PS3.set(135);
      PS4.set(67.5);
      break;

    case 4:
      PS1.set(270);
      PS2.set(202.5);
      PS3.set(157.5);
      PS4.set(90);
      break;

    case 5:
      PS1.set(247.5);
      PS2.set(202.5);
      PS3.set(157.5);
      PS4.set(112.5);
      break;

    case 6:
      PS1.set(225);
      PS2.set(202.5);
      PS3.set(157.5);
      PS4.set(135);
      break;

    case 7:
      PS1.set(202.5);
      PS2.set(180);
      PS3.set(180);
      PS4.set(157.5);
      break;

    case 8:
      PS1.set(180);
      PS2.set(180);
      PS3.set(180);
      PS4.set(180);
      break;

    case 9:
      PS4.set(202.5);
      PS3.set(180);
      PS2.set(180);
      PS1.set(157.5);
      break;

    case 10:
      PS4.set(225);
      PS3.set(202.5);
      PS2.set(157.5);
      PS1.set(135);
      break;

    case 11:
      PS4.set(247.5);
      PS3.set(202.5);
      PS2.set(157.5);
      PS1.set(112.5);
      break;

    case 12:
      PS4.set(270);
      PS3.set(202.5);
      PS2.set(157.5);
      PS1.set(90);
      break;

    case 13:
      PS4.set(292.5);
      PS3.set(225);
      PS2.set(135);
      PS1.set(67.5);
      break;

    case 14:
      PS4.set(315);
      PS3.set(225);
      PS2.set(135);
      PS1.set(45);
      break;

    case 15:
      PS4.set(337.5);
      PS3.set(225);
      PS2.set(135);
      PS1.set(22.5);
      break;

    default:
      PS1.reset();
      PS2.reset();
      PS3.reset();
      PS4.reset();
      break;
  }
}
