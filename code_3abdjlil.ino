#define enA 11
#define in1 10
#define in2 9
#define in3 8
#define in4 7
#define enB 5
#define R_S 13
#define C_S 2
#define L_S 12
#define L A0
#define R 0

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
  pinMode(C, INPUT);
  pinMode(L, INPUT);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(enA,255);
  analogWrite(enB,255);
  delay(1000);
}

void loop(){
  Serial.print(digitalRead(L_S));
  Serial.print(digitalRead(C_S));
  Serial.print(digitalRead(R_S));
  Serial.println();
  if ((digitalRead(L_S) == 1) && (digitalRead(C_S) == 0) && (digitalRead(R_S) == 1))
    forward();
  if ((digitalRead(L_S) == 0) && (digitalRead(C_S) == 1) && (digitalRead(R_S) == 1))
    turnRight();
  if ((digitalRead(L_S) == 1) && (digitalRead(C_S) == 1) && (digitalRead(R_S) == 0))
    turnLeft();
  if ((digitalRead(L_S) == 1) && (digitalRead(C_S) == 1) && (digitalRead(R_S) == 1))
    stop();
//LES ANGLES

  if ((digitalRead(L_S) == 0) && (digitalRead(C_S) == 0) && (digitalRead(R_S) == 1) && (digitalRead(R) == 1) && (digitalRead(L) == 0))
    turnRight();//probleme ici 
  if ((digitalRead(L_S) == 1) && (digitalRead(C_S) == 0) && (digitalRead(R_S) == 0) && (digitalRead(R) == 0) && (digitalRead(L) == 1))
    turnLeft();
//noeud +
  if ((digitalRead(L_S) == 0) && (digitalRead(C_S) == 0) && (digitalRead(R_S) == 0) && (digitalRead(R) == 0) && (digitalRead(L) == 0))
    forward();
}

void forward(){ 
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}

void turnRight(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft(){
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
