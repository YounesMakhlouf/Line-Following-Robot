#define enA 11
#define in1 10
#define in2 9
#define in3 8
#define in4 7
#define enB 5
#define R_S A5
#define C_S A4
#define L_S A3
#define L A0
#define R A1

// Analog sensor threshold and motor speeds
#define threshold (950+20)/2
#define MAX_SPEED_A 125
#define MAX_SPEED_B 135
#define TURNING_SPEED 170

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);
  pinMode(C_S, INPUT);
  pinMode(R, INPUT);
  pinMode(L, INPUT);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(enA,MAX_SPEED_A);
  analogWrite(enB,MAX_SPEED_B);
  delay(1000);
}

void loop(){
  // Read values from line sensors
  int line1 = read_eye(L_S);
  int line2 = read_eye(C_S);
  int line3 = read_eye(R_S);
  int line4 = read_eye(L);
  int line5 = read_eye(R);
  /*Serial.print(analogRead(L));
  Serial.print( " || ");  
  Serial.print(analogRead(L_S));
  Serial.print( " || ");
  Serial.print(analogRead(C_S));
  Serial.print( " || "); 
  Serial.print(analogRead(R_S));
  Serial.print( " || "); 
  Serial.print(analogRead(R));
  Serial.print( " || ");
  Serial.println();*/

  // Line following logic
  if ((line1 == 1) && (line2 == 0) && (line3 == 1))
    forward();

  if ((line1 == 0) && (line2 == 1) && (line3 == 1))
    turnRight();
 
  if ((line1 == 1) && (line2 == 1) && (line3 == 0))
    turnLeft();

    
  
  // Angle handling
  if ((line1 == 0) && (line2 == 0) && (line3 == 1) && (line4 ==0) && (line5==1))
    powerRight(); 
  if ((line1 == 1) && (line2 == 0) && (line3 == 0) && (line4==1) && (line5==0))
    powerLeft();

  // Handle node "+"
  if ((line1 == 0) && (line2 == 0) && (line3 == 0) && (line4 == 0) && (line5 == 0))
    forward();
 /* if ((line1 == 0) && (line2 == 0)  && (line4 == 1) && (line3 == 0) && (line5 == 0))
    turnLeft();*/
  }


// Read analog sensor and return LineState
int read_eye(int eye) {
  if (analogRead(eye) < threshold) return 0;
  return 1;
}

// Motor control functions
void forward(){ 
  changeSpeed(MAX_SPEED_A, MAX_SPEED_B);
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}

void turnRight(){
  changeSpeed(MAX_SPEED_A, MAX_SPEED_B);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft(){
  changeSpeed(MAX_SPEED_A, MAX_SPEED_B);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void powerRight(){
  changeSpeed(MAX_SPEED_A, TURNING_SPEED);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void powerLeft(){
 changeSpeed(TURNING_SPEED, MAX_SPEED_B);
 digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void changeSpeed(int speed_a, int speed_b) {
 analogWrite(enA, speed_a); 
 analogWrite(enB, speed_b); 
}
