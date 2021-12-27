#include "reg51.h"

//led 7-seg output data 0-9 
code unsigned char LEDfont[] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90 };

// time
unsigned int timer = 0;

//Define led 7-seg anot control (on/off):	
sbit LED7SEG_0 = P1 ^ 0;
sbit LED7SEG_1 = P1 ^ 1;
sbit LED7SEG_2 = P1 ^ 2;
sbit LED7SEG_3 = P1 ^ 3;

//Buzzer (speaker) connects on P1^5 
sbit SPK = P1 ^ 5;	//Buzzer on/off
//Relay connects on P1^4
sbit JDQ = P1 ^ 4;	//Relay on/off

sbit key1 = P3 ^ 2;	//Push button 1
sbit key2 = P3 ^ 3;	//Push button 2
sbit key3 = P3 ^ 4;	//Push button 3
sbit key4 = P3 ^ 5;	//Push button 4

void delay(unsigned int time) {
    while (time--);
}
// ham delay_ms sử dụng timer 
void delay_ms(int ms) {
    while (ms--) {
        TMOD = 0x01;
        TH0 = 0xFC;
        TL0 = 0x18;
        TR0 = 1;
        while (!TF0);
        TF0 = 0;
        TR0 = 0;
    }
}
unsigned char i;
void display(unsigned char time) {
    P0 = 0xFF;//Port 0 data off
    for (i = 0;i < 50;i++) {
        // mỗi frame 20ms nên 1s sẽ có 50 frames
        LED7SEG_2 = 0;P0 = LEDfont[time / 10];delay_ms(10);LED7SEG_2 = 1;
        LED7SEG_3 = 0;P0 = LEDfont[time % 10];delay_ms(10);LED7SEG_3 = 1;
    }
}

unsigned int status = 0;// biến trạng thái
unsigned int countDown = 1;
//button1
void EXT0(void) interrupt 1{
    EA = 0;// cam ngat
    status = 1;
    EA = 1;// cho phep ngat
    delay(100);
}
//button2
void EXT1(void) interrupt 2{
    EA = 0;// cam ngat
    status = 0;
    EA = 1;// cho phep ngat
    delay(100);
}

// Main program	
// code chính Đặng Công Nam
// code phụ, tester Bùi Nhật Quang			
void main(void) {
    // off speaker,motor
    SPK = 0;
    JDQ = 0;
    // cau hinh ngat ngoai
    EX0 = 1;
    EX1 = 1;
    IT0 = 1;
    IT1 = 1;
    EA = 1;
    while (1) {
        if (status) {
            countDown--;
            JDQ = 1;// on motor
        }
        else {
            JDQ = 0;// off motor
            // button3,4 nút bấm có delay nên ko dc nhạy
            // giữ lì sẽ cộng đều lên
            // mong thầy thông cảm ạ!
            // bỏ qua countDown==0
            // khi countDown==0 chuông reo
            if (key3 == 0) {
                delay(100);
                if (key3 == 0)
                    if (countDown == 99)countDown = 1;
                    else countDown++;
            }
            // button4
            if (key4 == 0) {
                delay(100);
                if (key4 == 0) {
                    if (countDown == 1)countDown = 99;
                    else countDown--;
                }
            }
        }
        display(countDown);
        if (countDown == 0) {
            JDQ = 0;// off motor
            LED7SEG_2 = 0;// hiển thị led7_3
            LED7SEG_3 = 0;// hiển thị led7_4
            SPK = 1;// on speaker
            delay_ms(3000);
            SPK = 0;// off speaker
            countDown = 1;
            status = 0;
        }
    }
}

