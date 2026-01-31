#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

void px(SDL_Renderer* r, int x, int y, int s, int rd=255, int g=255, int b=255) { 
    SDL_Rect rc={x,y,s,s}; 
    SDL_SetRenderDrawColor(r, rd, g, b, 255); 
    SDL_RenderFillRect(r,&rc); 
}

// Fixed Letter Logic
void drawL(SDL_Renderer* r, char c, int x, int y, int s) {
    if(c=='L'){for(int i=0;i<5;i++)px(r,x,y+i*s,s);for(int i=0;i<3;i++)px(r,x+i*s,y+4*s,s);}
    else if(c=='O'){for(int i=0;i<5;i++){px(r,x,y+i*s,s);px(r,x+2*s,y+i*s,s);}for(int i=0;i<3;i++){px(r,x+i*s,y,s);px(r,x+i*s,y+4*s,s);}}
    else if(c=='A'){for(int i=0;i<5;i++){px(r,x,y+i*s,s);px(r,x+2*s,y+i*s,s);}for(int i=0;i<3;i++){px(r,x+i*s,y,s);px(r,x+i*s,y+2*s,s);}}
    else if(c=='D'){for(int i=0;i<5;i++)px(r,x,y+i*s,s);px(r,x+s,y,s);px(r,x+2*s,y+s,s);px(r,x+2*s,y+2*s,s);px(r,x+2*s,y+3*s,s);px(r,x+s,y+4*s,s);}
    else if(c=='I'){for(int i=0;i<3;i++){px(r,x+i*s,y,s);px(r,x+i*s,y+4*s,s);}for(int i=0;i<5;i++)px(r,x+s,y+i*s,s);}
    else if(c=='N'){for(int i=0;i<5;i++){px(r,x,y+i*s,s);px(r,x+2*s,y+i*s,s);}px(r,x+s,y+s,s);px(r,x+s,y+2*s,s);}
    else if(c=='G'){for(int i=0;i<5;i++)px(r,x,y+i*s,s);for(int i=0;i<3;i++)px(r,x+i*s,y,s);for(int i=0;i<3;i++)px(r,x+i*s,y+4*s,s);px(r,x+2*s,y+2*s,s);px(r,x+2*s,y+3*s,s);}
    else if(c=='S'){for(int i=0;i<3;i++)px(r,x+i*s,y,s);px(r,x,y+s,s);for(int i=0;i<3;i++)px(r,x+i*s,y+2*s,s);px(r,x+2*s,y+3*s,s);for(int i=0;i<3;i++)px(r,x+i*s,y+4*s,s);}
    else if(c=='H'){for(int i=0;i<5;i++){px(r,x,y+i*s,s);px(r,x+2*s,y+i*s,s);}for(int i=0;i<3;i++)px(r,x+i*s,y+2*s,s);}
    else if(c=='T'){for(int i=0;i<3;i++)px(r,x+i*s,y,s);for(int i=0;i<5;i++)px(r,x+s,y+i*s,s);}
    else if(c=='E'){for(int i=0;i<5;i++)px(r,x,y+i*s,s);for(int i=0;i<3;i++){px(r,x+i*s,y,s);px(r,x+i*s,y+2*s,s);px(r,x+i*s,y+4*s,s);}}
    else if(c=='R'){for(int i=0;i<5;i++)px(r,x,y+i*s,s);px(r,x+s,y,s);px(r,x+2*s,y+s,s);px(r,x+s,y+2*s,s);px(r,x+2*s,y+3*s,s);px(r,x+2*s,y+4*s,s);}
    else if(c=='B'){for(int i=0;i<5;i++)px(r,x,y+i*s,s);for(int i=0;i<3;i++){px(r,x+i*s,y,s);px(r,x+i*s,y+2*s,s);px(r,x+i*s,y+4*s,s);}px(r,x+2*s,y+s,s);px(r,x+2*s,y+3*s,s);}
    else if(c=='X'){px(r,x,y,s);px(r,x+2*s,y,s);px(r,x+s,y+s,s);px(r,x+s,y+2*s,s);px(r,x+s,y+3*s,s);px(r,x,y+4*s,s);px(r,x+2*s,y+4*s,s);}
    else if(c=='C'){for(int i=0;i<5;i++)px(r,x,y+i*s,s);for(int i=0;i<3;i++){px(r,x+i*s,y,s);px(r,x+i*s,y+4*s,s);}}
    else if(c=='U'){for(int i=0;i<5;i++){px(r,x,y+i*s,s);px(r,x+2*s,y+i*s,s);}for(int i=0;i<3;i++)px(r,x+i*s,y+4*s,s);}
    else if(c=='M'){for(int i=0;i<5;i++){px(r,x,y+i*s,s);px(r,x+4*s,y+i*s,s);}px(r,x+s,y+s,s);px(r,x+2*s,y+2*s,s);px(r,x+3*s,y+s,s);}
    else if(c=='V'){for(int i=0;i<4;i++){px(r,x,y+i*s,s);px(r,x+2*s,y+i*s,s);}px(r,x+s,y+4*s,s);}
    else if(c=='Y'){px(r,x,y,s);px(r,x+2*s,y,s);px(r,x+s,y+s,s);px(r,x+s,y+2*s,s);px(r,x+s,y+3*s,s);px(r,x+s,y+4*s,s);}
}

void drawNum(SDL_Renderer* r, int n, int x, int y, int s) {
    SDL_Rect d;
    if(n!=1&&n!=4){d={x,y,3*s,s};SDL_RenderFillRect(r,&d);}
    if(n!=1&&n!=2&&n!=3&&n!=7){d={x,y,s,3*s};SDL_RenderFillRect(r,&d);}
    if(n!=5&&n!=6){d={x+2*s,y,s,3*s};SDL_RenderFillRect(r,&d);}
    if(n!=0&&n!=1&&n!=7){d={x,y+2*s,3*s,s};SDL_RenderFillRect(r,&d);}
    if(n==0||n==2||n==6||n==8){d={x,y+2*s,s,3*s};SDL_RenderFillRect(r,&d);}
    if(n!=2){d={x+2*s,y+2*s,s,3*s};SDL_RenderFillRect(r,&d);}
    if(n!=1&&n!=4&&n!=7){d={x,y+4*s,3*s,s};SDL_RenderFillRect(r,&d);}
}

void draw4Digit(SDL_Renderer* r, int v, int x, int y, int s) {
    drawNum(r,(v/1000)%10,x,y,s); drawNum(r,(v/100)%10,x+(4*s),y,s);
    drawNum(r,(v/10)%10,x+(8*s),y,s); drawNum(r,v%10,x+(12*s),y,s);
}

void drawEnemy(SDL_Renderer* r, SDL_Rect e) {
    int s = e.w/6; SDL_SetRenderDrawColor(r,180,0,0,255); SDL_RenderFillRect(r,&e);
    px(r,e.x,e.y-s,s,255,0,0); px(r,e.x+e.w-s,e.y-s,s,255,0,0); // Horns
    px(r,e.x+s,e.y+s*2,s,255,255,255); px(r,e.x+e.w-s*2,e.y+s*2,s,255,255,255); // Eyes
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO); srand(time(NULL));
    SDL_Window* w=SDL_CreateWindow("Shooter Box",0,0,400,800,0);
    SDL_Renderer* ren=SDL_CreateRenderer(w,-1,0);
    SDL_Rect p={170,700,60,60}, b={0,-100,10,30}, e1={rand()%340,0,60,60}, e2={rand()%340,-400,60,60};
    int sc=0, hiSc=0, state=-1, blink=0, loadP=0, speed=12;

    while(1) {
        SDL_Event ev;
        while(SDL_PollEvent(&ev)) {
            if(ev.type==SDL_QUIT) return 0;
            if(ev.type==SDL_FINGERDOWN) {
                int ty=ev.tfinger.y*800;
                if(state==0 && ty>330) state=1;
                else if(state==2 && ty>330) {state=1; sc=0; e1.y=0; e2.y=-400; b.y=-100;}
            }
            if(ev.type==SDL_FINGERMOTION) p.x=ev.tfinger.x*400-30;
        }

        SDL_SetRenderDrawColor(ren,10,10,25,255); SDL_RenderClear(ren);

        if(state==-1) { // 1. LOADING
            int lx=100, ly=350, ls=7;
            drawL(ren,'L',lx,ly,ls); drawL(ren,'O',lx+25,ly,ls); drawL(ren,'A',lx+50,ly,ls); drawL(ren,'D',lx+75,ly,ls);
            drawL(ren,'I',lx+105,ly,ls); drawL(ren,'N',lx+130,ly,ls); drawL(ren,'G',lx+160,ly,ls);
            SDL_Rect bar={50,450,300,20}, fill={50,450,loadP*3,20};
            SDL_SetRenderDrawColor(ren,50,50,50,255); SDL_RenderFillRect(ren,&bar);
            SDL_SetRenderDrawColor(ren,0,255,150,255); SDL_RenderFillRect(ren,&fill);
            if(++loadP>=100) state=0;
        }
        else if(state==0) { // 2. SHOOTER BOX (HOME)
            int tx=45, ty=100, ts=10;
            drawL(ren,'S',tx,ty,ts); drawL(ren,'H',tx+35,ty,ts); drawL(ren,'O',tx+70,ty,ts); drawL(ren,'O',tx+105,ty,ts); drawL(ren,'T',tx+140,ty,ts); drawL(ren,'E',tx+175,ty,ts); drawL(ren,'R',tx+210,ty,ts);
            drawL(ren,'B',130,220,12); drawL(ren,'O',175,220,12); drawL(ren,'X',220,220,12);
            SDL_Rect sBtn={20,330,360,440}; SDL_SetRenderDrawColor(ren,0,255,100,255); SDL_RenderDrawRect(ren,&sBtn);
            if((++blink/15)%2==0){ int sx=105; drawL(ren,'S',sx,520,8); drawL(ren,'T',sx+30,520,8); drawL(ren,'A',sx+60,520,8); drawL(ren,'R',sx+90,520,8); drawL(ren,'T',sx+120,520,8); }
        } 
        else if(state==1) { // 3. GAMEPLAY
            e1.y+=speed; e2.y+=speed;
            if(e1.y>800){e1.y=-50; e1.x=rand()%340;} if(e2.y>800){e2.y=-50; e2.x=rand()%340;}
            if(b.y < 0){b.x=p.x+25; b.y=p.y-10;} b.y-=35;
            if(SDL_HasIntersection(&p,&e1)||SDL_HasIntersection(&p,&e2)){state=2; if(sc>hiSc)hiSc=sc;}
            if(SDL_HasIntersection(&b,&e1)){sc++; b.y=-100; e1.y=-100; e1.x=rand()%340;}
            if(SDL_HasIntersection(&b,&e2)){sc++; b.y=-100; e2.y=-100; e2.x=rand()%340;}
            SDL_SetRenderDrawColor(ren,0,255,150,255); SDL_RenderFillRect(ren,&p);
            drawEnemy(ren,e1); drawEnemy(ren,e2);
            SDL_SetRenderDrawColor(ren,255,255,0,255); SDL_RenderFillRect(ren,&b);
            draw4Digit(ren,sc,15,20,5);
        } 
        else if(state==2) { // 4. GAME OVER
            SDL_SetRenderDrawColor(ren,60,0,0,255); SDL_RenderClear(ren);
            int gx=80; drawL(ren,'G',gx,40,5); drawL(ren,'A',gx+20,40,5); drawL(ren,'M',gx+40,40,5); drawL(ren,'E',gx+75,40,5);
            drawL(ren,'O',gx+105,40,5); drawL(ren,'V',gx+125,40,5); drawL(ren,'E',gx+145,40,5); drawL(ren,'R',gx+165,40,5);
            int cx=30, cy=140, cs=3;
            drawL(ren,'C',cx,cy,cs); drawL(ren,'U',cx+12,cy,cs); drawL(ren,'R',cx+24,cy,cs); drawL(ren,'R',cx+36,cy,cs); drawL(ren,'E',cx+48,cy,cs); drawL(ren,'N',cx+60,cy,cs); drawL(ren,'T',cx+72,cy,cs);
            drawL(ren,'S',cx+90,cy,cs); drawL(ren,'C',cx+102,cy,cs); drawL(ren,'O',cx+114,cy,cs); drawL(ren,'R',cx+126,cy,cs); drawL(ren,'E',cx+138,cy,cs);
            draw4Digit(ren,sc,cx+165,cy,4);
            drawL(ren,'B',cx,cy+60,cs); drawL(ren,'E',cx+12,cy+60,cs); drawL(ren,'S',cx+24,cy+60,cs); drawL(ren,'T',cx+36,cy+60,cs);
            drawL(ren,'S',cx+54,cy+60,cs); drawL(ren,'C',cx+66,cy+60,cs); drawL(ren,'O',cx+78,cy+60,cs); drawL(ren,'R',cx+90,cy+60,cs); drawL(ren,'E',cx+102,cy+60,cs);
            draw4Digit(ren,hiSc,cx+165,cy+60,4);
            for(int i=0;i<5;i++) for(int j=0;j<3;j++) px(ren, 260+j*4, cy+58+i*4, 4, 255, 215, 0); // Trophy
            SDL_Rect rBtn={20,330,360,440}; SDL_SetRenderDrawColor(ren,0,255,100,255); SDL_RenderDrawRect(ren,&rBtn); 
            if((++blink/15)%2==0){ int rx=95; drawL(ren,'R',rx,520,8); drawL(ren,'E',rx+35,520,8); drawL(ren,'T',rx+70,520,8); drawL(ren,'R',rx+105,520,8); drawL(ren,'Y',rx+140,520,8); }
        }
        SDL_RenderPresent(ren); SDL_Delay(16);
    }
    return 0;
}
