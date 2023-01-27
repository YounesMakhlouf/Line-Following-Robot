#define enA 11
#define in1 10
#define in2 9
#define in3 8
#define in4 7
#define enB 5


// Vitesse du moteur
int state = 0;

void setup() {
    Serial.begin(9600);

    // Configuration des ports en mode "sortie"
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);
    delay(400);

    Serial.println("Moteur A avance vitesse maximale");
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    delay(500);
    analogWrite(enA,255);
    analogWrite(enB,255);
    delay(200000);
/*
    Serial.println("Moteur B avance vitesse maximale");
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    delay(500);
    analogWrite(enA,0);
    analogWrite(enB,255);
    delay(2000);
    
     Serial.println("Moteur A recule vitesse maximale");
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(500);
    analogWrite(enA,255);
    analogWrite(enB,0);
    delay(2000);

    Serial.println("Moteur B recule vitesse maximale");
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    delay(500);
    analogWrite(enA,0);
    analogWrite(enB,255);
    delay(2000);

    analogWrite(enA,0);
    analogWrite(enB,255);
    delay(100); 

    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);*/
}

void loop(){

}
 