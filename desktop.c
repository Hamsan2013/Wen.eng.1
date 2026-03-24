extern void clear(char);
extern void draw_rect(int,int,int,int,char);

void render_lock(){

clear(20);

draw_rect(120,60,80,80,250);

}

void render_desktop(){

clear(30);

draw_rect(0,0,320,20,60);

draw_rect(120,90,80,40,120);

}

void render_store(){

clear(40);

draw_rect(0,0,320,30,80);

draw_rect(250,170,60,20,200);

}
