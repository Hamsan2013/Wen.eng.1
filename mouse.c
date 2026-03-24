unsigned char inb(unsigned short port){
unsigned char r;
asm volatile("inb %1,%0":"=a"(r):"Nd"(port));
return r;
}

void outb(unsigned short port,unsigned char data){
asm volatile("outb %0,%1": :"a"(data),"Nd"(port));
}

void mouse_init(){

outb(0x64,0xA8);

outb(0x64,0x20);

unsigned char status=inb(0x60);

status|=2;

outb(0x64,0x60);

outb(0x60,status);

}
