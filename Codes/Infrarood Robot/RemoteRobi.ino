//-----------------
//include libraries
//-----------------
#include <IRremote.h>    
#include <IRremoteInt.h>
#include <Servo.h> 

  int const IRpin = 7;            // Define IR pin
  IRrecv irrecv(IRpin);
  decode_results IRresult;

  Servo rightServo;
  Servo leftServo;
  
//-------------
//Servo forward
//-------------
int const rsff =       0;         // Right Servo Forward Fast
int const lsff =     180;         // Left Servo Forward Fast

int const rsfs =      85;         // Right Servo Forward Slow
int const lsfs =     116;         // Left Servo Forward Slow

//-------------
//Servo reverse
//-------------
int const rsrf =     180;         // Right Servo Reverse Fast
int const lsrf =       0;         // Left Servo Reverse Fast

int const rsrs =     99;          // Right Servo Reverse Slow
int const lsrs =      56;         // Left Servo Reverse Slow

//-----
//Break
//-----
int const rsbr =      90;         // Right Servo Break
int const lsbr =      90;         // Left Servo Break

int const startUpLed =    11;     // Pin connected to the start up LED

byte input = '0';                 // IR-Remote control     


//---------------------------------------- 
// Translate button code to simpler naming
//----------------------------------------
int btnCHMin = 93;                //Read out for button (CH-)
int btnCH = 157;                  //Read out for button (CH)
int btnCHPlus = 29;               //Read out for button (CH+)

int btnPrev = 221;                //Read out for button (PREV)
int btnNext = 253;                //Read out for button (NEXT)
int btnPlayPause = 61;            //Read out for button (PLAY/PAUSE)

int btnVolMin = 31;               //Read out for button (VOL-)
int btnVolPlus = 87;              //Read out for button (VOL+
int btnEQ = 111;                  //Read out for button (EQ)


int btn0 = 151;                   //Read out for button (0)
int btn100Plus = 103;             //Read out for button (100+)
int btn200Plus = 79;              //Read out for button (200+)

int btn1 = 207;                   //Read out for button (1)
int btn2 = 231;                   //Read out for button (2)
int btn3 = 133;                   //Read out for button (3)

int btn4 = 239;                   //Read out for button (4)
int btn5 = 199;                   //Read out for button (5)
int btn6 = 165;                   //Read out for button (6)

int btn7 = 189;                   //Read out for button (7)
int btn8 = 181;                   //Read out for button (8)
int btn9 = 173;                   //Read out for button (9)

void setup() {                  
  
  Serial.begin(9600);
  irrecv.enableIRIn();            // Start the receiver
   Serial.begin(9600);
  while(!Serial);                 //Wait for serial connection
  Serial.println("setup():            Hello there. ");

  //Define Servos
  rightServo.attach(10);   
  leftServo.attach(8);
  
  pinMode(startUpLed, OUTPUT);    // ontvangstledje
  startFlash();                   // Flashing signal

  
}

void loop()
{
  unsigned long currentMillis = millis();
   if (irrecv.decode(&IRresult)){ 
       
     //LED lash when receiving a command                       
     digitalWrite(startUpLed, HIGH); 
     delay(10);
     digitalWrite(startUpLed, LOW);
     
     Serial.println(IRresult.value);
     irrecv.resume();
     
     input =(IRresult.value); 
     Serial.println(input);
  }
//--------------
//Slow manouvres
//--------------
  if(input == btnCH){             //Slow forward
    forwardSlow();
  }
  if(input == btnPrev){           //Slow turn left
    turnLeftForwardSlow();
  }
  if(input == btnPlayPause){      //Slow turn right
    turnRightForwardSlow();
  }
  if(input == btnVolPlus) {       //Slow reverse
    reverseSlow();
  }
//--------------
//Fast manouvres
//--------------
  if(input == btn2){              //Fast forward
    forwardFast();     
  }
  if(input == btn4){              //Fast turn left
    turnLeftForwardFast();
  }
   if(input == btn6){             //Fast turn right
    turnRightForwardFast();
  }
   if(input == btn8){             //Fast reverse
    reverseFast();
  }
//----------------
//Slight manouvres
//----------------
   if(input == btn1){             //Slight turn left forward
    slightTurnLeftForward();
  }
   if(input == btn3){             //Slight turn right forward
    slightTurnRightForward();
  }
   if(input == btn7){             //Slight turn left reverse
    slightTurnLeftReverse();
  }
   if(input == btn9){             //Slight turn right reverse
    slightTurnRightReverse();
  }
//---------------
//Dance manouvres
//---------------
   if(input == btnCHMin){         //Dance 1
    danceOne();
  }
   if(input == btnCHPlus){        //Dance 2
    danceTwo();
  }
//--------------
//Break manouvre
//--------------
  if(input == btn5){              //Break
    hitBreaks();     
  }
 
}

//---------
//Functions
//---------

//-----------------
//Starting up flash
//-----------------
void startFlash(){    
  Serial.println("startFlash():  flash 3 times.");
  
    digitalWrite(startUpLed, HIGH);
    delay(100);
    digitalWrite(startUpLed, LOW);
    delay(1000);
    digitalWrite(startUpLed, HIGH);
    delay(200);
    digitalWrite(startUpLed, LOW);
    delay(1000);
    digitalWrite(startUpLed, HIGH);
    delay(300);
    digitalWrite(startUpLed, LOW);
    delay(1000);
}

//--------------
//Fast manouvres
//--------------
void forwardFast(){        
    Serial.println("forwardFast():      Full speed forward.");
    rightServo.write(rsfs);       //Start slow to reduce bump
    leftServo.write(lsfs); 
    delay(500);
    rightServo.write(rsff);
    leftServo.write(lsff);
}
void turnRightForwardFast(){
    Serial.println("turnRightForwardFast():      Full speed to the right.");
    rightServo.write(rsbr);
    leftServo.write(lsff);    
}
void turnLeftForwardFast(){
    Serial.println("turnLeftForwardFast():      Full speed to the left.");
    rightServo.write(rsff);
    leftServo.write(lsbr);
}
void reverseFast(){
    Serial.println("reverseFast():      Full speed reverse.");
    rightServo.write(rsrs);       //Start slow to reduce bump
    leftServo.write(lsrs); 
    delay(500);
    rightServo.write(rsrf);
    leftServo.write(lsrf);
}

//----------------
//Slight manouvres
//----------------
void slightTurnLeftForward(){
    Serial.println("slightTurnLeftForward():      Slight turn to left forward.");
    rightServo.write(rsff);
    leftServo.write(lsfs);
}

void slightTurnRightForward() {
    Serial.println("slightTurnRightForward():      Slight turn to right forward.");
    rightServo.write(rsfs);
    leftServo.write(lsff);
}
void slightTurnLeftReverse() {
    Serial.println("slightTurnLeftReverse():      Slight turn to left reverse.");
    rightServo.write(rsrf);
    leftServo.write(lsrs);
}
void slightTurnRightReverse() {
    Serial.println("slightTurnRightReverse():      Slight turn to right reverse.");
    rightServo.write(rsrs);
    leftServo.write(lsrf);
}

//--------------
//Slow manouvres
//--------------
void forwardSlow(){   
    Serial.println("forwardSlow():      Slow speed forward.");
    rightServo.write(rsfs);
    leftServo.write(lsfs); 
}
void turnRightForwardSlow(){
    Serial.println("turnRightForwardSlow():      Slow speed to the right.");
    rightServo.write(rsbr);
    leftServo.write(lsfs);
}
void turnLeftForwardSlow(){
    Serial.println("turnLeftForwardSlow():      Slow speed to the left.");
    rightServo.write(rsfs);
    leftServo.write(lsbr);
}
void reverseSlow(){
    Serial.println("reverseSlow():      Slow speed reverse.");
    rightServo.write(rsrs);
    leftServo.write(lsrs);
}

//---------------
//Dance manouvres
//---------------
void danceOne(){
    Serial.println("danceOne():          Performing dance 1");
//Start dancing
    rightServo.write(rsff);
    leftServo.write(lsbr);
    delay(250);
    rightServo.write(rsbr);
    leftServo.write(lsff);
    delay(250);
    rightServo.write(rsrf);
    leftServo.write(lsrf);
    delay(500);
    rightServo.write(rsbr);
    leftServo.write(lsff);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsbr);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsff);
    delay(750);
    rightServo.write(rsrf);
    leftServo.write(lsff);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsrf);
    delay(100);
    rightServo.write(rsrf);
    leftServo.write(lsff);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsrf);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsff);
    delay(500);
    rightServo.write(rsbr);
    leftServo.write(lsbr);
//Stop dancing
}
void danceTwo(){
    Serial.println("danceTwo():          Performing dance 2");
//Start dancing
    rightServo.write(rsbr);
    leftServo.write(lsff);
    delay(3000);
    rightServo.write(rsff);
    leftServo.write(lsff);
    delay(500);
    rightServo.write(rsff);
    leftServo.write(lsbr);
    delay(2000);
    rightServo.write(rsff);
    leftServo.write(lsff);
    delay(1000);
    rightServo.write(rsff);
    leftServo.write(lsrf);
    delay(100);
    rightServo.write(rsrf);
    leftServo.write(lsff);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsrf);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsrf);
    delay(100);
    rightServo.write(rsrf);
    leftServo.write(lsff);
    delay(100);
    rightServo.write(rsff);
    leftServo.write(lsrf);
    delay(100);
    rightServo.write(rsrf);
    leftServo.write(lsrf);
    delay(500);
    rightServo.write(rsbr);
    leftServo.write(lsff);
    delay(200);
    rightServo.write(rsff);
    leftServo.write(lsbr);
    delay(200);
    rightServo.write(rsbr);
    leftServo.write(lsff);
    delay(200);
    rightServo.write(rsff);
    leftServo.write(lsbr);
    delay(200);
    rightServo.write(rsbr);
    leftServo.write(lsff);
    delay(200);
    rightServo.write(rsff);
    leftServo.write(lsbr);
    delay(200);
    rightServo.write(rsbr);
    leftServo.write(lsff);
    delay(200);
    rightServo.write(rsbr);
    leftServo.write(lsbr);
//Stop with dancing
}

//--------------
//Break manouvre
//--------------
void hitBreaks(){           
    Serial.println("hitBreaks():          Hitting the breaks");
    rightServo.write(rsbr);   
    leftServo.write(lsbr); 
}
