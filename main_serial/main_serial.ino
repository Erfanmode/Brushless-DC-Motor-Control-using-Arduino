//#define REMOTEXY__DEBUGLOG 
// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT
#include <RemoteXY.h>


// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "krfanEsp"
#define REMOTEXY_WIFI_PASSWORD "passerfan"
#define REMOTEXY_SERVER_PORT 6377
//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG  
#define IR 2
#define Motor_voltage 6
float time=0;
int det1,det2;
float velocity,t=0,vel=0;
float sum=0;
int time0;
int i;
float u,ui=0,up;
float Kp,Ki;
int start_signal=0;



// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 36 bytes
  { 255,1,0,32,0,29,0,16,54,1,4,128,6,75,53,5,2,26,67,5,
  21,22,20,5,2,26,21,67,5,21,47,20,5,2,26,11 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider_1; // =0..100 slider position 

    // output variables
  char text_1[21];  // string UTF8 end zero 
  char text_2[21];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

void setup() {
 //RemoteXY_Init ();
 Serial.begin(9600);
 pinMode(IR, INPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(6,OUTPUT);
}
void loop() {
digitalWrite(11,HIGH);digitalWrite(12,LOW);
time0=millis();
velocity=500;
 det2= 1;
 sum=0;
 i=1;
 Kp=0.3;
 Ki=0.0007;
 ui=0;
 while(1){
  //RemoteXY_Handler ();
  //velocity=RemoteXY.slider_1*4600/100;
  if(start_signal){ui+=(velocity-vel)*Ki*t/1000;}
  up=Kp*(velocity-vel);
  u =int( up + ui );
  if(u>255){u=255;}
  analogWrite(6,u);
  det1=det2;
  det2 = digitalRead(IR);
  if(det1-det2 == 1){
    start_signal=1;
    t=millis()-time;
    time=millis();
    vel=60/t*1000;
  }
  i++;
  sum+=vel;
  // dtostrf(sum/i/4500,0,1,RemoteXY.text_1);
   //dtostrf(RemoteXY.slider_1,0,1,RemoteXY.text_1);
  if(i>400){Serial.print(ui);Serial.print(' ');Serial.print(up);Serial.print(' ');Serial.println(sum/i);i=1;sum=0;}
 }
}




