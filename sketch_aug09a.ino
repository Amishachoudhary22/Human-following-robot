int p1=10;
int p2=9;
int p3=3;
int p4=4;

int IRL=8;
int IRR=2;
int IRB=5;
bool IR_L;
bool IR_R;
bool IR_B;

int trigPin=7;
int echoPin=6;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);

  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IRB,INPUT);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  Serial.begin(9600);
}


void loop() {
  digitalWrite(trigPin,LOW);
  delay(2000);
  digitalWrite(trigPin,HIGH);
  delay(1000);
  digitalWrite(trigPin,LOW);
  duration= pulseIn(echoPin,HIGH);
  distance= duration* 0.032/2;

  IR_L =digitalRead(IRL);
  IR_R =digitalRead(IRR);
  IR_B =digitalRead(IRB);
  
  if(distance>= 10 && distance <= 30){
    if(IR_L ==1 & IR_R ==1)
    {
      digitalWrite(p1,HIGH);
      digitalWrite(p2,LOW);
      digitalWrite(p3,HIGH);
      digitalWrite(p4,LOW);
    }
    else if(IR_L ==0 & IR_R ==1)
    {
      digitalWrite(p1,LOW);
      digitalWrite(p2,HIGH);
      digitalWrite(p3,LOW);
      digitalWrite(p4,HIGH);
    }
    else if(IR_L ==1 & IR_R ==0)
    {
      digitalWrite(p1,HIGH);
      digitalWrite(p2,LOW);
      digitalWrite(p3,HIGH);
      digitalWrite(p4,LOW);
    }
    else 
    {
      digitalWrite(p1,LOW);
      digitalWrite(p2,LOW);
      digitalWrite(p3,LOW);
      digitalWrite(p4,LOW);
    }
  }
  else if(distance<= 5 && IR_B ==1){
    digitalWrite(p1,LOW);
    digitalWrite(p2,HIGH);
    digitalWrite(p3,LOW);
    digitalWrite(p4,HIGH);
  }
  else
  {
    digitalWrite(p1,LOW);
    digitalWrite(p2,LOW);
    digitalWrite(p3,LOW);
    digitalWrite(p4,LOW);
  }
  // put your main code here, to run repeatedly:

}
