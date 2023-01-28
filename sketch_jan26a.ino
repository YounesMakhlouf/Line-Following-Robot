#define enA 11
#define in1 10
#define in2 9
#define in3 8
#define in4 7
#define enB 5
#define R_S 1
#define L_S 2
#define C_S 3

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
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enA,255);
  analogWrite(enB,255);
}

void loop(){
  if ((L_S == 1) && (C_S == 0) && (R_S == 1))
    forward();
  if ((L_S == 0) && (C_S == 1) && (R_S == 1))
    turnRight();
  if ((L_S == 1) && (C_S == 1) && (R_S == 0))
    turnLeft();
  if ((L_S == 1) && (C_S == 1) && (R_S == 1))
    stop();
}

void forward(){ 
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}

void turnRight(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
