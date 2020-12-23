#define EN1 10

#define IN1 8

#define IN2 7

 

#define EN2 9

#define IN3 6

#define IN4 5



unsigned char GSMDataLen;

char AppState;

String SerialCommand=””;

boolean CommandReceived;

 

void setup()

{

delay(500);             //Startup delay

 

pinMode(EN1,OUTPUT);

pinMode(IN1,OUTPUT);

pinMode(IN2,OUTPUT);

 

pinMode(EN2,OUTPUT);

pinMode(IN3,OUTPUT);

pinMode(IN4,OUTPUT);

 

Serial.begin(9600);



SerialCommand.reserve(150);

Stop();

 

GSMDataLen=0;

AppState=1;

CommandReceived=0;

SerialCommand=””;


}

 

void loop()

{

switch(AppState)

{

case 1:

{

AppState=2;

break;

}

case 2:

{

if(CommandReceived)

{

CommandReceived=0;

GSMDataLen=SerialCommand.length();

 

//Call hangup

if(SerialCommand.charAt(2)==’R’ && SerialCommand.charAt(3)==’I’ && SerialCommand.charAt(4)==’N’ && SerialCommand.charAt(5)==’G’)

{

Serial.print(F(“ATH0\r\n”));


delay(2000);

}
