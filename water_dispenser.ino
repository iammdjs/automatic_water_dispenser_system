#define trigger 9
#define echo 8
#define LED 13
#define SYSTEM 12

float time = 0,distance=0;

void setup() {

 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(SYSTEM,OUTPUT);

 delay(2000);

}

void loop() {
  measure_distance();

 if(distance<16)
 {
   digitalWrite(LED,HIGH);digitalWrite(SYSTEM,HIGH);
 }
 else
 {
   digitalWrite(LED,LOW);digitalWrite(SYSTEM,LOW);
 }

 delay(500);

}

void measure_distance()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 
 distance = time*340/20000;
}
