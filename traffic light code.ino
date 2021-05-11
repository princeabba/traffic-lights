int red1 =4;
int green1=2;
int yellow1 = 3;
int red2 =10;
int green2 =8;
int yellow2 =9;
int red3 =13;
int green3 =11;
int yellow3 =12;
int red4 =7;
int green4 =5;
int yellow4 =6;
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 3000;
const long wait = 3000;
void check();
void setup(){
Serial.begin(9600);
pinMode(red1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(red3, OUTPUT);
pinMode(red4, OUTPUT);
pinMode(green1, OUTPUT);
pinMode(green2, OUTPUT);
pinMode(green3, OUTPUT);
pinMode(green4, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(yellow3, OUTPUT);
pinMode(yellow4, OUTPUT);
digitalWrite(red1, LOW);
digitalWrite(red2, LOW);
digitalWrite(red3, LOW);
digitalWrite(red4, LOW);
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
digitalWrite(green3, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);
  
}
int stt = 2; //Variable to control timing;
char j;
void loop(){
unsigned long currentMillis = millis();
if(stt ==2){
previousMillis = currentMillis; //move to way 1
Serial.println("going on 1");// set green1 to high and all other variables as zero
digitalWrite(green1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(red4, HIGH);
// set all other to low except red and green1
digitalWrite(red1, LOW);
digitalWrite(green2, LOW);
digitalWrite(green3, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);
stt = 30;
}
  if (currentMillis - previousMillis >= interval && stt ==30) {
previousMillis = currentMillis;
stt =3;  // after a wait of 3 seconds set green1 low and yellow1 high
digitalWrite(green1, LOW);
digitalWrite(red2, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(red4, HIGH);
digitalWrite(yellow1, HIGH);
}
if (currentMillis - previousMillis >= wait && stt ==3) {
  stt = 4; // after a wait of 3 seconds set yellow 1 to low and green3 to high
previousMillis = currentMillis;    
digitalWrite(yellow1, LOW);

}
if (stt == 4){
stt =5;
Serial.println("going on 3"); //MOVE TOWAY 3
digitalWrite(green3, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(red1, HIGH);
digitalWrite(red4, HIGH);
digitalWrite(red3, LOW);
// set all other to low except green3
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);

}
if (currentMillis - previousMillis >= interval && stt ==5) {
 digitalWrite(green3, LOW); // after a wait of 3 seconds set green3 low and yellow3 high
 digitalWrite(yellow3, HIGH);
 previousMillis = currentMillis; 
stt=6;
}
if (currentMillis - previousMillis >= wait && stt ==6) {
  stt = 7;
digitalWrite(yellow3, LOW);
}
if(stt==7){
stt=8;
previousMillis = currentMillis;
Serial.println("going on 2");  // MMOVE TO WAY 2
digitalWrite(green2, HIGH);
digitalWrite(red1, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(red4, HIGH);  
digitalWrite(red2, LOW);

// set all other to low except 
digitalWrite(green1, LOW);
digitalWrite(green3, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);

}
if (currentMillis - previousMillis >= interval && stt ==8) {
 previousMillis = currentMillis;
 digitalWrite(green2, LOW);
 digitalWrite(red1, HIGH);
 digitalWrite(red3, HIGH);
 digitalWrite(red4, HIGH);
 digitalWrite(yellow2, HIGH);
stt =9;
}
if (currentMillis - previousMillis >= wait && stt ==9) {
  stt = 10;
 digitalWrite(yellow2, LOW);
}
if (stt ==10 ){
previousMillis = currentMillis;
Serial.println("going on 4");
digitalWrite(green4, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(red1, HIGH);
digitalWrite(red4, LOW);  
stt=12;
}
if (currentMillis - previousMillis >= interval && stt ==12) {
 previousMillis = currentMillis;
  digitalWrite(green4, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, LOW);
  digitalWrite(yellow4, HIGH);
 stt=13;
 }
 if (currentMillis - previousMillis >= wait && stt ==13) {
  stt = 18;
 previousMillis = currentMillis;
  digitalWrite(yellow4, LOW);
  digitalWrite(red4, HIGH);


}
 if (currentMillis - previousMillis >= wait && stt ==18) {
  stt=2;
digitalWrite(red1, LOW);
digitalWrite(red2, LOW);
digitalWrite(red3, LOW);
digitalWrite(red4, LOW);
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
digitalWrite(green3, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);

 }

if(Serial.available()>0){
  check();  
}
}
void check(){
   j = Serial.read();
   if(j== 'u'){
stt = 14;
 unsigned long currentMillis = millis();
Serial.println("going on 4");
digitalWrite(green4, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(red1, HIGH);
digitalWrite(red4, LOW);
// Set all other to low apart from green 4 
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
digitalWrite(green3, LOW);
//digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);


  if (currentMillis - previousMillis >= interval) {
stt = 2;
}
   }
      if(j== 'r'){
stt = 15;
 unsigned long currentMillis = millis();
Serial.println("going on 1");
digitalWrite(green1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(red4, HIGH);
digitalWrite(red1, LOW);
// set all other to low except green 1
//digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
digitalWrite(green3, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);

  if (currentMillis - previousMillis >= interval) {
stt = 2;
}
   }
     if(j== 'l'){
stt = 16;
 unsigned long currentMillis = millis();
Serial.println("going on 3");
digitalWrite(green3, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(red1, HIGH);
digitalWrite(red4, HIGH);
digitalWrite(red3, LOW);
// set all other to low except green3
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
//digitalWrite(green3, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);

  if (currentMillis - previousMillis >= interval) {
stt = 2;
}
   }
    if(j== 'd'){
stt = 17;
 unsigned long currentMillis = millis();
Serial.println("going on 2");  
digitalWrite(green2, HIGH);
digitalWrite(red1, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(red4, HIGH);
digitalWrite(red2, LOW);
// set all other to low except green2
digitalWrite(green1, LOW);
//digitalWrite(green2, LOW);
digitalWrite(green3, LOW);
digitalWrite(green4, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(yellow4, LOW);

  if (currentMillis - previousMillis >= interval) {
stt = 2;
}
   }
  
}
