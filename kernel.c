#define FB 0xA0000
#define W 320
#define H 200

int unlocked=0;
int screen=0;

void plot(int x,int y,char c){
((char*)FB)[y*W+x]=c;
}

void clear(char c){
for(int i=0;i<W*H;i++)
((char*)FB)[i]=c;
}

void draw_rect(int x,int y,int w,int h,char c){
for(int j=y;j<y+h;j++)
for(int i=x;i<x+w;i++)
plot(i,j,c);
}

extern void render_lock();
extern void render_desktop();
extern void render_store();

void kernel_main(){

while(1){

if(unlocked==0)
render_lock();

else if(screen==0)
render_desktop();

else
render_store();

asm("hlt");

}

}
