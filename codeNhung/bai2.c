#include "reg51.h"

//Hex codes to display numbers (0-9) on a 7-segment anode display
code unsigned char LEDfont[] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90 };
unsigned char i, j, z;
unsigned int LEDdata = 1;
//Define 7-seg anode display control (on/off):	
sbit LED7SEG_0 = P1 ^ 0;	//7-seg 1 anode display 
sbit LED7SEG_1 = P1 ^ 1;	//7-seg 2 anode display
sbit LED7SEG_2 = P1 ^ 2;	//7-seg 3 anode	display
sbit LED7SEG_3 = P1 ^ 3;	//7-seg 4 anode display

//Relay connects on P1^4
sbit JDQ = P1 ^ 4;	//Relay on/off

//Buzzer (speaker) connects on P1^5 
sbit SPK = P1 ^ 5;	//Buzzer on/offF

//Delay 0-65536
void delay(unsigned int time) {
	while (time--);
}

void bai11() {
	P2 = 0x00;// đèn bật
	delay(20000);
	P2 = 0xff;// đèn tắt
	delay(20000);
}
void bai12() {
	for (i = 0;i <= 7;i++) {
		unsigned char k = 1;
		k <<= i;// bật đèn ở bit i bằng phép xor 1^1=0
		P2 = P2 ^ k;
		delay(20000);
		P2 = 0xff;
	}
}
void bai13() {
	//khi for down từ 7->0 bị lỗi. em ko phát hiện ra nguyên nhân
	// nên đã for up
	for (i = 0;i <= 7;i++) {
		unsigned char k = 1;
		k <<= 7 - i;
		P2 = P2 ^ k;// bật đèn ở bit 7- i bằng phép xor 1^1=0		
		delay(20000);
		P2 = 0xff;
	}
}
void bai14() {
	for (i = 0;i <= 6;i++) {
		unsigned char k = 1;
		unsigned char h = 0;
		// h=00000000
		k <<= i;
		h += k;
		k = 1;
		k <<= i + 1;
		h += k;
		//h=01100000 
		P2 = P2 ^ h;
		delay(20000);
		P2 = 0xff;
	}
	for (i = 0;i <= 6;i++) {
		unsigned char k = 1;
		unsigned char h = 0;
		// h=00000000
		k <<= 7 - i;
		h += k;
		k = 1;
		k <<= 7 - i - 1;
		h += k;
		//h=01100000 
		P2 = P2 ^ h;
		delay(20000);
		P2 = 0xff;
	}
}
void bai15() {
	// bien h bi identify nen em cho vao for z
	for (z = 0; z < 1;z++) {
		unsigned char h = 0xff;
		for (i = 7;i > 0;i--) {
			// for j la dich den
			for (j = 0;j <= i;j++) {
				unsigned char k = 1;
				P2 = h;
				k <<= j;
				P2 = P2 ^ k;
				delay(20000);
			}
			// lưu cấu hình khi dich xong i đèn
			h = P2;
		}
		P2 = 0x00;
		delay(20000);
		for (i = 0;i <= 7;i++) {
			h = 1;
			h <<= 7 - i;
			P2 = P2 ^ h;
			delay(20000);
		}
	}
}
void bai16() {
	// tuong tu bai 4 nhung 2 bit doi nhau
	for (i = 0;i < 4;i++) {
		unsigned char k = 1;
		unsigned char h = 0;
		h = 0;
		h += k << i;
		h += k << 7 - i;
		P2 ^= h;
		delay(20000);
		P2 = 0xff;
	}
	for (i = 0;i < 3;i++) {
		unsigned char k = 1;
		unsigned char h = 0;
		h = 0;
		h += k << 2 - i;
		h += k << 5 + i;
		P2 ^= h;
		delay(20000);
		P2 = 0xff;
	}
	delay(20000);
}
void display(unsigned char num) {
	P0 = 0xFF;
	LED7SEG_0 = 1;
	LED7SEG_1 = 1;
	LED7SEG_2 = 1;
	LED7SEG_3 = 0;
	P0 = LEDfont[num];
}
//button1
//khi bấm nút thì chương trình hoàn thành phần đang chạy mới chuyển 
void EXT0(void) interrupt 1{
	EA = 0;	//cấm ngắt
	if (LEDdata == 6) LEDdata = 1;
	else LEDdata++;
	EA = 1;//cho phép ngắt
	delay(100);
}
//button2
void EXT1(void) interrupt 2{
	EA = 0;	//cấm ngắt
	if (LEDdata == 1) LEDdata = 6;
	else LEDdata--;
	EA = 1;//cho phép ngắt
	delay(100);
}

// Main program	
// code chính Đặng Công Nam
// code phụ, tester Bùi Nhật Quang				
void main(void) {
	SPK = 0;
	JDQ = 0;
	// cấu hình ngắt ngoài
	EX0 = 1;
	EX1 = 1;
	IT0 = 1;
	IT1 = 1;
	EA = 1;
	P0 = 0;
	while (1) {
		P2 = 0xff;
		display(LEDdata);// hiển thị số
		if (LEDdata == 1)bai11();
		else if (LEDdata == 2)bai12();
		else if (LEDdata == 3)bai13();
		else if (LEDdata == 4)bai14();
		else if (LEDdata == 5)bai15();
		else if (LEDdata == 6)bai16();
		delay(1000);
	}
}