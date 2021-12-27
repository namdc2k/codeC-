#include "reg51.h"
unsigned char i, j, z;

//Relay connects on P1^4
sbit JDQ = P1 ^ 4;	//Relay on/off
//Buzzer (speaker) connects on P1^5 
sbit SPK = P1 ^ 5;	//Buzzer on/off


//Delay 0-65536
void delay(unsigned int time) {
    while (time--);
}

void bai11() {
    for (z = 0;z < 3;z++) {
        P2 = 0x00;// đèn bật
        delay(20000);
        P2 = 0xff;// đèn tắt
        delay(20000);
    }
}
void bai12() {
    for (z = 0;z < 3;z++)
        for (i = 0;i <= 7;i++) {
            unsigned char k = 1;
            k <<= i;// bật đèn ở bit i bằng xor 1^1=0
            P2 = P2 ^ k;
            delay(20000);
            P2 = 0xff;
        }
}
//em for tu 7->0 nhưng đèn số 1 không sáng nên em đã for 0->7
void bai13() {
    for (z = 0;z < 3;z++)
        for (i = 0;i <= 7;i++) {
            unsigned char k = 1;
            k <<= 7 - i;
            P2 = P2 ^ k;// bật đèn ở bit 7-i 1^1=0		
            delay(20000);
            P2 = 0xff;
        }
}
void bai14() {
    for (z = 0;z < 3;z++) {
        for (i = 0;i <= 6;i++) {
            unsigned char k = 1;
            unsigned char h = 0;
            // h=00000000
            k <<= i;
            h += k;
            k = 1;
            k <<= i + 1;
            h += k;
            //h=11000000 
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
            //h=00000011 
            P2 = P2 ^ h;
            delay(20000);
            P2 = 0xff;
        }
    }
}
void bai15() {
    for (z = 0;z < 3;z++) {
        unsigned char h = 0xff;
        for (i = 7;i > 0;i--) {
            // for j để dịch đèn
            for (j = 0;j <= i;j++) {
                unsigned char k = 1;
                P2 = h;
                k <<= j;
                P2 = P2 ^ k;
                delay(20000);
            }
            // lưu trạng thái khi đã dịch dc i đèn
            h = P2;
        }
        // tắt đèn
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
    for (z = 0;z < 3;z++) {
        // tương tự bài 4 nhung 2 bit doi nhau
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
}

// Main program	
// code chính Đặng Công Nam
// code phụ, tester Bùi Nhật Quang				
void main(void) {
    SPK = 0;
    JDQ = 0;
    bai11();
    bai12();
    bai13();
    bai14();
    bai15();
    bai16();
}