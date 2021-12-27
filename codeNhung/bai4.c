#include "reg51.h"

//led 7-seg output data 0-9 
code unsigned char LEDfont[] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90 };
unsigned char LEDpos = 1;	//choose led 7-seg position	

// time
unsigned int timer = 0;

//Define led 7-seg anot control (on/off):	
sbit LED7SEG_0 = P1 ^ 0;
sbit LED7SEG_1 = P1 ^ 1;
sbit LED7SEG_2 = P1 ^ 2;
sbit LED7SEG_3 = P1 ^ 3;

//Buzzer (speaker) connects on P1^5 
sbit SPK = P1 ^ 5;	//Buzzer on/off

//Delay 0-65536
void delay(unsigned int time) {
    while (time--);
}
// ham hien thi
void displayLed(unsigned int time) {
    P0 = 0xFF;//Port 0 data off
    switch (LEDpos) {
    case 1:		//choose led 7-seg 1
        LED7SEG_0 = 0;
        LED7SEG_1 = 1;
        LED7SEG_2 = 1;
        LED7SEG_3 = 1;
        P0 = LEDfont[time / 1000];  //Chu so hang nghin
        break;
    case 2:		//choose led 7-seg 2
        LED7SEG_0 = 1;
        LED7SEG_1 = 0;
        LED7SEG_2 = 1;
        LED7SEG_3 = 1;
        P0 = LEDfont[time / 100 % 10] - 0x80;	//Chu so hang tram
        //	0x80 là bit 1 cua dp
        break;
    case 3:		//choose led 7-seg 3
        LED7SEG_0 = 1;
        LED7SEG_1 = 1;
        LED7SEG_2 = 0;
        LED7SEG_3 = 1;
        P0 = LEDfont[time / 10 % 10]; //Chu so hang chuc
        break;
    case 4:		//choose led 7-seg 4
        LED7SEG_0 = 1;
        LED7SEG_1 = 1;
        LED7SEG_2 = 1;
        LED7SEG_3 = 0;
        P0 = LEDfont[time % 10]; //Chu so hang don vi
        break;
    }
    LEDpos++;
    if (LEDpos > 4)
        LEDpos = 1;
}
unsigned int status = 0;

void EXT0(void) interrupt 1{
    status = 1;
    delay(100);
}
//button2
void EXT1(void) interrupt 2{
    status = 0;
    delay(100);
}
// Main program	
// code chính Bùi Nhật Quang
// code phụ, tester Đặng Công Nam				
void main(void) {
    //cau hinh ngat ngoai
    EX0 = 1;
    EX1 = 1;
    IT0 = 1;
    IT1 = 1;
    EA = 1;
    SPK = 0;// off speaker
    while (1) {
        displayLed(timer);
        // delay em ước tính sau vài lần thử với
        // đồng hồ bấm giờ ở điện thoại
        delay(1000);
        if (status){
            if (timer < 9999) {
                timer++;
            }
            else timer = 0;
        }
    }
}
