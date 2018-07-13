#include<Servo.h>

Servo xservo;
Servo yservo;
Servo zservo;
Servo wservo;

char ch;
int v=0,i=0,xcur=0,xprev=90,ycur=0,yprev=90,zcur=0,zprev=90,wcur=0,wprev=90;
int d=5; //delay

void setup() {
wservo.attach(6);
xservo.attach(9);
yservo.attach(10);
zservo.attach(11);
Serial.begin(9600);
wservo.write(90);
xservo.write(90);
yservo.write(90);
zservo.write(90);
}


void loop() {
  // put your main code here, to run repeatedly
 
  if(Serial.available()>0)
   {
    ch=Serial.read();
    switch(ch)
    {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':v=v*10+ch-'0';
               break;
      case 'w':wcur=v;
               wprev=Servowrite(wservo,wcur,wprev);
               break;  
      case 'x':xcur=v;
               xprev=Servowrite(xservo,xcur,xprev);
               break;  
      case 'y':ycur=v;
               yprev=Servowrite(yservo,ycur,yprev);
               break;  
      case 'z':zcur=v;
               zprev=Servowrite(zservo,zcur,zprev);               
               break; 
         case 's':Serial.println("Settings");       
      default:break;
    }
   }

}


int Servowrite(Servo s,int cur,int prev)
{
  if(prev<cur)
    { for(i=prev;i<=cur;i++)
        {s.write(i);
         delay(d);
         }
     } 
   else if(cur<prev)
     { for(i=prev;i>=cur;i--)
         {s.write(i);
          delay(d);
         }
     }
     Serial.println();
     Serial.print("prev=");
     Serial.println(prev);
     Serial.print("cur=");
     Serial.println(cur);
     v=0;
     return cur;
}

