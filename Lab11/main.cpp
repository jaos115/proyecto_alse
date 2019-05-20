#include <wiringPi.h>

enum estado{
	A,
	B,
    C,
    D
};

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main (int argc, char**argv){
  wiringPiSetup () ;
  estado est;
  est = D;
  //int intensidad = 0;
  bool btn1, btn2, btn3;
  btn1 = btn2 = btn3 = false;
  while(true){
        btn1 = digitalRead(0);
        btn2 = digitalRead(2);
        btn3 = digitalRead(3);

        if( btn1 ){
          if(est == A )
             est = D;
          else if(est == B)
             est = B;
          else if(est == C)
             est = C;
          else if (est == D)
              est = A;
        }

        if( btn2 ){
            if(est == A )
                 est = B;
            else if(est == B)
                 est = A;
            else if(est == C)
                 est = A;
            else if (est == D)
                est = D;

        }

        if( btn3 ){
            if(est == A )
                 est = A;
            else if(est == B)
                 est = C;
            else if(est == C)
                 est = C;
            else if (est == D)
                est = D;

        }

   switch( est ){
	  case A:
        pinMode(1,OUTPUT);
        pinMode(4,OUTPUT);
        pinMode(5,OUTPUT);
        digitalWrite(1,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        delay(300);
        digitalWrite(1,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        delay(300);
        break;

	  case B:
		digitalWrite(1,HIGH);
        delay(200);
		digitalWrite(1,LOW);
        digitalWrite(4,HIGH);
        delay(200);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        delay(200);
        digitalWrite(5, LOW);
		break;

	  case C:
       digitalWrite(5,HIGH);
       delay(200);
       digitalWrite(5,LOW);
       digitalWrite(4,HIGH);
       delay(200);
       digitalWrite(4,LOW);
       digitalWrite(1,HIGH);
       delay(200);
       digitalWrite(1, LOW);
       break;

       case D:
       digitalWrite(1, LOW);
       digitalWrite(4, LOW);
       digitalWrite(5, LOW);
       delay(200);

	}
  }

  return 0 ;
}

