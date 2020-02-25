#include "mbed.h"
#include "C12832.h"

C12832 lcd(p5, p7, p6, p8, p11);

BusIn up(p15);
BusIn down(p12);
BusIn left(p13);
BusIn right(p16);
DigitalIn centre(p14);

BusOut led1(LED1);
BusOut led2(LED2);
BusOut led3(LED3);
BusOut led4(LED4);

int wins_needed = 4;
int times_won = 0;
int lives = 3;
bool won = false;

void check(){
    if (times_won >= wins_needed){
        won = true;
        lcd.cls();
        lcd.locate(0,15);
        lcd.printf("you won congratz");
            
    }
}
void count_trys(){
    lcd.cls();
    lcd.locate(0,3);
    lcd.printf("you have Wins = %d",times_won);
    wait(0.5);
}

void restart(){
    times_won = 0;
    won = false;
    }

int main(){
    while(1){
        if(centre){
                led1=0xf;
                led2=0xf;
                led3=0xf;
                led4=0xf;
                wait(0.5);
                led1=0;
                led2=0;
                led3=0;
                led4=0;
                restart();
        }
        while (won == false){
            //game code
            led1 = 1;
            wait(5.0);
            if ((led1 == 1) && (down)){
                times_won = times_won + 1;
            }
            
            led1 = 0;
            
            check();
            count_trys();
            //
            led2 = 1;
            wait(5.0);
            if ((led2 == 1) && (left)){
                times_won = times_won + 1;
            }
            led2 = 0;
            
            check();
            count_trys();
            //
            led3 = 1;
            wait(5.0);
            if ((led3 == 1) && (up)){
                times_won = times_won + 1;
            }
            led3 = 0;
            
            check();
            count_trys();
            //
            led4 = 1;
            wait(5.0);
            if ((led4 == 1) && (right)){
                times_won = times_won + 1;
            }
            led4 = 0;
            check();
            count_trys();
            
        }
        
    }
}
