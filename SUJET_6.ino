int trigPin=3;
int echoPin=2;

int revleft4 = 6;//REVerse motion of Left motor
int fwdleft5 = 9;//ForWarD motion of Left motor
int revright6 = 10;//REVerse motion of Right motor
int fwdright7 = 11;//ForWarD motion of Right motor

long duration, distance;

void setup() {
delay(random(500,2000));// delay for random time
Serial.begin(57600);
pinMode(revleft4, OUTPUT);// set Motor pins as output
pinMode(fwdleft5, OUTPUT);
pinMode(revright6, OUTPUT);
pinMode(fwdright7, OUTPUT);
pinMode(trigPin, OUTPUT);// set trig pin as output
pinMode(echoPin, INPUT);//set echo pin as input to capture reflected waves
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);// send waves for 10 us
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH);// receive reflected waves
distance = duration / 58.2;// convert to distance
delay(10);
Serial.println(distance);
if (distance > 10)
{
analogWrite(fwdright7, 0);// move forward
analogWrite(revright6, 100);
analogWrite(fwdleft5, 100);
analogWrite(revleft4, 0);
}
if (distance < 10){
analogWrite(fwdright7, 0);
analogWrite(revright6, 0);
analogWrite(fwdleft5, 0);
analogWrite(revleft4, 0);
delay(500);
analogWrite(fwdright7, 0);
analogWrite(revright6, 100);
analogWrite(fwdleft5, 0);
analogWrite(revleft4, 100);
delay(500);
analogWrite(fwdright7, 0);
analogWrite(revright6, 0);
analogWrite(fwdleft5, 0);
analogWrite(revleft4, 0);
delay(100);

}

}
