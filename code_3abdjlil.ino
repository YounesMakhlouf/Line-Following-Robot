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
#define threshold (950+20)/2
#define MAX_SPEED_A 150
#define MAX_SPEED_B 190

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
  int line1 = read_eye(L_S);
  int line2 = read_eye(C_S);
  int line3 = read_eye(R_S);
  int line4 = read_eye(L);
  int line5 = read_eye(R);

   Serial.print(analogRead(L));
  Serial.print( " || ");  
  Serial.print(analogRead(L_S));
  Serial.print( " || ");
   Serial.print(analogRead(C_S));
  Serial.print( " || "); 
   Serial.print(analogRead(R_S));
  Serial.print( " || "); 
  Serial.print(analogRead(R));
  Serial.print( " || ");
  Serial.println();
  
  if ((line1 == 1) && (line2 == 0) && (line3 == 1))
    forward();
  if ((line1 == 0) && (line2 == 1) && (line3 == 1))
    turnRight();
  if ((line1 == 1) && (line2 == 1) && (line3 == 0))
    turnLeft();
  if ((line1 == 1) && (line2 == 1) && (line3 == 1))
    stop();
//LES ANGLES
  
  if ((line1 == 0) && (line2 == 0) && (line3 == 1))
    turnRight();//probleme ici 
  if ((line1 == 1) && (line2 == 0) && (line3 == 0))
    turnLeft();
//noeud +
  if ((line1 == 0) && (line2 == 0) && (line3 == 0) && (line4 == 0) && (line5 == 0))
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
int read_eye(int eye) {
 int line = analogRead(eye);
 if (line < threshold) return 0;
 return 1;
}
