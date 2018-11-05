#include <stdio.h>
#include <wiringPi.h>
#include "morsecode.h"

#define TIME_UNIT 500
#define DOT_TIME (TIME_UNIT)
#define DASH_TIME (TIME_UNIT*3)
#define LETTER_SPACE_TIME (TIME_UNIT*3)
#define WORD_SPACE_TIME (TIME_UNIT*7)


void init_morse(void)
{
wiringPiSetup () ; 
pinMode (0, OUTPUT) ;
pinMode (1, OUTPUT) ;
}

void send_dot(void)
{digitalWrite(0, HIGH);delay(DOT_TIME);
}

void send_dash(void) 
{digitalWrite(0, HIGH);delay(DASH_TIME);
}

void wait_letter(void)
{
  digitalWrite(0, LOW); delay(LETTER_SPACE_TIME);

  printf("wait for letter\n");
}

void wait_dot(void)
{
  digitalWrite(0, LOW); delay(DOT_TIME);
  printf("wait for dot\n");
}

void wait_word(void)
{
  digitalWrite(0, LOW); delay(WORD_SPACE_TIME);
  printf("wait for word\n");
}

void play_buzzer(int msec)
{digitalWrite (1, HIGH) ; delay (msec) ;
digitalWrite (1, LOW) ;
}

char *char2morse(char c)
{
  if(c=='1'){
return "*====";
}
else if(c=='2'){
return"**===";
}
else if(c=='3'){ 
return"***==";
}
else if(c=='4'){ 
return"****=";
}
else if(c=='5'){ 
return"*****";
}
else if(c=='6'){ 
return"=****";
}
else if(c=='7'){ 
return"==***";
}
else if(c=='8'){ 
return"===**";
}
else if(c=='9'){ 
return"====*";
}
else
{return"=====";
}

}
