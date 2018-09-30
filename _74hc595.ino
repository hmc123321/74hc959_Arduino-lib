#define DS 9
#define STCP 11
#define SHCP 10
#define OE 12
#define MR 2
#define ulong unsigned long 
#define uchar unsigned char 
#define uint unsigned int 
void hc595_16 (uint data);
uint ctl(uchar h,uchar l);
void setup() {
  pinMode (SHCP,1);
  pinMode (STCP,1);
  pinMode (DS,1);
  pinMode (MR,1);
  pinMode (OE,1);
  digitalWrite (OE,LOW);
  digitalWrite (MR,HIGH);
}
void loop() {
   hc595_16(cti(0x7f,0xfe));
   while (1);
}
void hc595_16 (uint data){
  digitalWrite (STCP,LOW);
  for (int i=0;i<16;i++){
    digitalWrite (SHCP,LOW);
    digitalWrite (DS,data>>15);
    digitalWrite (SHCP,HIGH);
    data<<=1;
    }
  digitalWrite (STCP,HIGH);
  digitalWrite (STCP,LOW);
}

void hc595_8 (uchar data){
  int i=0;
  digitalWrite (STCP,LOW);
  for (;i<8;i++){
    digitalWrite (SHCP,LOW);
    digitalWrite (DS,data>>7);
    digitalWrite (SHCP,HIGH);
    data<<=1;
    }
  digitalWrite (STCP,HIGH);
  digitalWrite (STCP,LOW);
}

uint cti(uchar h,uchar l){//a function for combine two eight_bit data into one sixteen_bit data.
  uint data;
  data=(h/0x10)*0x1000+(h%0x10)*0x100+l;
  return data;
}
