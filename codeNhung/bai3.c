#include "reg51.h"

//led 7-seg output data 0-9 
code unsigned char LEDfont[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

// time
unsigned int timer = 0;

//Define led 7-seg anot control (on/off):	
sbit LED7SEG_0 = P1^0;	
sbit LED7SEG_1 = P1^1;	
sbit LED7SEG_2 = P1^2;	
sbit LED7SEG_3 = P1^3;	

//Buzzer (speaker) connects on P1^5 
sbit SPK  = P1^5;	//Buzzer on/off

// ham delay_milisecond sử dụng timer
void delay_ms(int ms){							    
	while(ms--){
		TMOD=0x01;
		TH0=0xFC;
		TL0=0x18;
		TR0=1;
		while(!TF0);
		TF0=0;
		TR0=0;
	}
}
unsigned char i;
// hiển thị số
void display(unsigned char time){
	P0=0xFF;//Port 0 data off
    // mỗi frame 20ms nên 1s sẽ có 50 frames
	for(i=0;i<50;i++){
		LED7SEG_2=0;P0=LEDfont[time/10];delay_ms(10);LED7SEG_2=1;
		LED7SEG_3=0;P0=LEDfont[time%10];delay_ms(10);LED7SEG_3=1;
	}
}

// Main program	
// code chính, tester Bùi Nhật Quang
void main(void) {
	SPK = 0;
	while (1){
		display(timer);
		if(timer<99) timer++;
		else timer=0;
	}
}