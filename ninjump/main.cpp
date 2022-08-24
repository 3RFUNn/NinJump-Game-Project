#include "SBDL.h"
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include<fstream>
#include <cmath>
using namespace std;
using namespace SBDL;
int x=0,emtiaz=0,seda=0,seda2=0,high=0,counter=0;
int speed=3,play=1;
char state = 'l';
char State = 'm';
bool charkh= false;
bool charkh2=false;
bool blade=true;
bool partabblade=true;
bool blade_a=true;
bool partabblade2=true;
bool blade_b=true;
bool partabblade3=true;
bool blade_c=true;
bool partabblade4=true;
bool sanjabbarkhord=true;
bool kaftarbarkhord=true;
bool kaftarbarkhord2=true;
bool tigh2=true;
bool tigh3=true;
bool tigh4=true;
bool tigh1=true;
bool sanjab;
bool shieldbarkhord=true;
Texture walls,Scoretext,highscore;
Texture nl1,nl2,nl3,nr1,nr2,nr3,nj1,nj2,nj3,nj4,nj5;
Texture nf1,nf2,nf3,enemy1,blade1,blade2,blade3,blade4;
Texture sl1,sl2,sl3,sl4;
Texture house,spike,bird1,bird2,bird3,shield;
Texture background,score,scoretext,menu,menu_play,Gameover,again,home,quit;
Texture rakhtaviz,pause;
Texture balcon;
Texture balcon2;
Texture khatar,seda_on,seda_off,sound_on;
Sound *jump,*click;
Font *font;
Sound *gameover,*fall,*rubah,*kaftar,*star;
Music *music;
    SDL_Rect houserect = {0, -50, 500, 600};
    SDL_Rect wallrect = {-452, 0, 492, 500};
    SDL_Rect wallrect2 = {-452, -490, 492, 500};
    SDL_Rect wallrect3 = {-452, -980, 492, 500};
    SDL_Rect wallrect4 = {456, 0, 492, 500};
    SDL_Rect wallrect5 = {456, -490, 492, 500};
    SDL_Rect wallrect6 = {456, -980, 492, 500};
    SDL_Rect runleftrect = {40, 400, 40, 40};
    SDL_Rect back = {0, 0, 500, 500};
    SDL_Rect rakht = {39, -1200, 418, 100};
    SDL_Rect balcony = {0, -5600, 150, 100};
    SDL_Rect balcony2 = {350, -4900, 150, 100};
    SDL_Rect squirrel = {27, -1215, 70, 40};
    SDL_Rect spikes = {0, -3600, 90, 150};
    SDL_Rect spikes2 = {410, -6200, 90, 150};
    SDL_Rect leftbird = {25, -1100, 60, 50};
    SDL_Rect rightbird = {440, -2500, 60, 50};
    SDL_Rect scorerect = {180, 0, 120, 50};
    SDL_Rect enemy1rect = {28, -500, 50, 60};
    SDL_Rect enemy2rect = {418, -1800, 50, 70};
    SDL_Rect bladechap = {28, -500, 20, 20};
    SDL_Rect bladechap2 = {28, -500, 20, 20};
    SDL_Rect bladerast = {418, -1800, 20, 20};
    SDL_Rect bladerast2 = {418, -1800, 20, 20};
    SDL_Rect khatar1 = {0, 20, 30, 30};
    SDL_Rect khatar2 = {460, 20, 30, 30};
    SDL_Rect menurect = {0, 0, 500, 500};
    SDL_Rect menu_playrect = {180, 350, 120, 120};
    SDL_Rect Seda = {360, 330, 70, 70};
    SDL_Rect Seda2 = {350, 290, 70, 70};
    SDL_Rect gameoverrect = {0, 0, 500, 500};
    SDL_Rect againrect = {120, 250, 70, 70};
    SDL_Rect homerect = {280, 245, 75, 75};
    SDL_Rect quitrect = {180, 360, 120, 50};
    SDL_Rect pauserect={0,0,500,500};
    SDL_Rect pauseplay={220,115,75,75};
    SDL_Rect Againrect={220,215,70,70};
    SDL_Rect Homerect={220,305,70,70};
    SDL_Rect quit2rect={30,400,100,50};
    SDL_Rect sound1={350,200,70,70};
    SDL_Rect menusound={360,410,70,70};
    SDL_Rect shieldrect={395,-300,60,60};
void loadkolli(){
    walls=loadTexture("E:/assets/background/back1.png");
    house=loadTexture("E:/assets/background/foreground.png");
    nr1=loadTexture("E:/assets/run/1.png");
    nr2=loadTexture("E:/assets/run/2.png");
    nr3=loadTexture("E:/assets/run/3.png");
    nl1=loadTexture("E:/assets/run/4.png");
    nl2=loadTexture("E:/assets/run/5.png");
    nl3=loadTexture("E:/assets/run/6.png");
    nj1=loadTexture("E:/assets/run/7.png");
    nj2=loadTexture("E:/assets/run/8.png");
    nj3=loadTexture("E:/assets/run/9.png");
    nj4=loadTexture("E:/assets/run/10.png");
    nj5=loadTexture("E:/assets/run/11.png");
    background=loadTexture("E:/assets/img/background.png");
    rakhtaviz=loadTexture("E:/assets/obstacles/rope/rope.png");
    balcon=loadTexture("E:/assets/obstacles/houses/balcony.png");
    balcon2=loadTexture("E:/assets/obstacles/houses/balcony3.png");
    nf1=loadTexture("E:/assets/falling/falling1.png");
    nf2=loadTexture("E:/assets/falling/falling2.png");
    nf3=loadTexture("E:/assets/falling/falling3.png");
    sl1=loadTexture("E:/assets/obstacles/squirrels/SQ1.png");
    sl2=loadTexture("E:/assets/obstacles/squirrels/SQ2.png");
    sl3=loadTexture("E:/assets/obstacles/squirrels/SQ3.png");
    sl4=loadTexture("E:/assets/obstacles/squirrels/SQ4.png");
    spike=loadTexture("E:/assets/obstacles/spike/SPIKES.png");
    bird1=loadTexture("E:/assets/obstacles/bird/bird1.png");
    bird2=loadTexture("E:/assets/obstacles/bird/bird2.png");
    bird3=loadTexture("E:/assets/obstacles/bird/bird3.png");
    jump=loadSound("E:/assets/sounds/jump_7.wav");
    gameover=loadSound("E:/assets/sound/gameover.wav");
    music=loadMusic("E:/assets/sound/Geisha.mp3");
    fall=loadSound("E:/assets/sounds/fall_1.wav");
    score=loadTexture("E:/assets/img/score.png");
    font=loadFont("E:/assets/fonts/font.ttf",30);
    enemy1=loadTexture("E:/assets/obstacles/thrower/thrower.png");
    blade1=loadTexture("E:/assets/obstacles/blade/1.png");
    blade2=loadTexture("E:/assets/obstacles/blade/2.png");
    blade3=loadTexture("E:/assets/obstacles/blade/3.png");
    blade4=loadTexture("E:/assets/obstacles/blade/4.png");
    rubah=loadSound("E:/assets/sounds/hit_squirrel_1.wav");
    kaftar=loadSound("E:/assets/sounds/hit_bird_2.wav");
    star=loadSound("E:/assets/sounds/hit_star_2.wav");
    khatar=loadTexture("E:/assets/obstacles/bird/khatar.png");
    menu=loadTexture("E:/assets/menu/back2.png");
    menu_play=loadTexture("E:/assets/menu/PLAYBTN.png");
    click=loadSound("E:/assets/sound/click.mp3");
    seda_on=loadTexture("E:/assets/img/sound_btn.png");
    seda_off=loadTexture("E:/assets/img/off_slash.png");
    Gameover=loadTexture("E:/assets/menu/gameover_panel.png");
    again=loadTexture("E:/assets/menu/again.png");
    home=loadTexture("E:/assets/menu/home.png");
    quit=loadTexture("E:/assets/menu/QUITBTN.png");
    pause=loadTexture("E:/assets/menu/PAUSEMENU.png");
    sound_on=loadTexture("E:/assets/menu/music_btn.png");
    shield=loadTexture("E:/assets/Shield/shield.png");
}
void rect(){
    houserect = {0, -50, 500, 600};
    wallrect = {-452, 0, 492, 500};
    wallrect2 = {-452, -490, 492, 500};
    wallrect3 = {-452, -980, 492, 500};
    wallrect4 = {456, 0, 492, 500};
    wallrect5 = {456, -490, 492, 500};
    wallrect6 = {456, -980, 492, 500};
    runleftrect = {40, 400, 40, 40};
    back = {0, 0, 500, 500};
    rakht = {39, -1200, 418, 100};
    balcony = {0, -5600, 150, 100};
    balcony2 = {350, -4900, 150, 100};
    squirrel = {27, -1215, 70, 40};
    spikes = {0, -3600, 90, 150};
    spikes2 = {410, -6200, 90, 150};
    leftbird = {25, -1100, 60, 50};
    rightbird = {440, -2500, 60, 50};
    scorerect = {180, 0, 120, 50};
    enemy1rect = {28, -500, 50, 60};
    enemy2rect = {418, -1800, 50, 70};
    bladechap = {28, -500, 20, 20};
    bladechap2 = {28, -500, 20, 20};
    bladerast = {418, -1800, 20, 20};
    bladerast2 = {418, -1800, 20, 20};
}
void main_menu(){
    showTexture(menu,menurect);
    showTexture(quit,quit2rect);
    showTexture(menu_play,menu_playrect);
        showTexture(seda_on, Seda);
    if(seda%2==1){
        showTexture(seda_off,Seda);
    }
    if(mouseInRect(Seda) && Mouse.clicked()){
        playSound(click,play);
        if(seda%2==1){
            seda2=0;
        }
        seda++;
    }
    showTexture(sound_on,menusound);
    if(play==0) {
        showTexture(seda_off, menusound);
    }
    if(mouseInRect(menusound) && Mouse.clicked()){
        if(play==1)
            play=0;
        else if(play==0)
            play=1;
    }
    if(mouseInRect(quit2rect)&& Mouse.clicked()) {
        ofstream fout("highscore.txt");
        fout << high << endl;
        stop();
    }
    if(mouseInRect(menu_playrect) && Mouse.clicked()) {
        playSound(click,play);
        emtiaz=0;
        speed=3;
        playMusic(music,-1);
        rect();
        State = 'G';
        state='l';
    }

}
void restart(){
    showTexture(Gameover,gameoverrect);
    showTexture(again,againrect);
    showTexture(home,homerect);
    showTexture(quit,quitrect);
    if(mouseInRect(againrect) && Mouse.clicked()) {
        playSound(click,play);

        emtiaz=0;
        speed=3;
        playMusic(music,-1);
        rect();
        State = 'G';
        state='l';
    }
    if(mouseInRect(quitrect) && Mouse.clicked()) {
        ofstream fout("highscore.txt");
        fout<<high<<endl;
        stop();
    }
    if(mouseInRect(homerect) && Mouse.clicked()) {
        playSound(click, play);
        State='m';
    }
    Scoretext=createFontTexture(font,"score:"+to_string(emtiaz),0,0,0);
    showTexture(Scoretext,190,45);
    highscore=createFontTexture(font,"highscore:"+to_string(high),0,0,0);
    showTexture(highscore,150,120);
}
void showenemy(){
    showTexture(enemy1,enemy1rect);
    enemy1rect.y+=speed;
    showTexture(enemy1,0,enemy2rect,SDL_FLIP_HORIZONTAL);
    enemy2rect.y+=speed;
    if(enemy1rect.y>500)
        enemy1rect.y=-2900;
    if(enemy2rect.y>500)
        enemy2rect.y=-2100;
    if(abs(balcony2.y-enemy1rect.y)<100 || abs(spikes2.y-enemy1rect.y)<100)
        enemy1rect.y-=300;
    if(abs(balcony.y-enemy2rect.y)<100 || abs(spikes.y-enemy2rect.y)<100)
        enemy2rect.y-=300;
    if(hasIntersectionRect(rakht,enemy1rect))
        enemy1rect.y-=200;
    if(hasIntersectionRect(rakht,enemy2rect))
        enemy2rect.y-=200;
    if(hasIntersectionRect(enemy1rect,spikes) || hasIntersectionRect(enemy1rect,balcony))
        enemy1rect.y-=100;
    if(hasIntersectionRect(enemy2rect,spikes2) || hasIntersectionRect(enemy2rect,balcony2))
        enemy2rect.y-=100;
    if(abs(enemy1rect.y-enemy2rect.y)<=100)
        enemy2rect.y-=300;

}
void showblade() {
    if (blade)
        bladerast.y += speed;
    if (bladerast.x < -400 || bladerast.y < 0) {
        blade = true;
        tigh3=true;
        bladerast.y = enemy2rect.y;
        partabblade = false;
        bladerast.x = 418;


    }
    if (bladerast.y > 450) {
        blade = false;
        partabblade = true;
    }
    if (partabblade) {
        bladerast.y -= 1;
        bladerast.x -= 5;
    }
    if (blade_a)
        bladerast2.y += speed;
    if (bladerast2.x < -400 || bladerast2.y < 0) {
        blade_a = true;
        tigh4=true;
        bladerast2.y = enemy2rect.y;
        partabblade2 = false;
        bladerast2.x = 418;


    }
    if (bladerast2.y > 0) {
        blade_a = false;
        partabblade2 = true;
    }
    if (partabblade2) {
        bladerast2.y += 6;
        bladerast2.x -= 5;
    }
    if (blade_b)
        bladechap.y += speed;
    if (bladechap.x > +1000 || bladechap.y < 0) {
        blade_b = true;
        tigh1 = true;
        bladechap.y = enemy1rect.y;
        partabblade3 = false;
        bladechap.x = 28;


    }
    if (bladechap.y > 450) {
        blade_b = false;
        partabblade3 = true;
    }
    if (partabblade3) {
        bladechap.y -= 1;
        bladechap.x += 5;
    }
    if (blade_c)
        bladechap2.y += speed;
    if (bladechap2.x > 1000 || bladechap2.y < 0) {
        blade_c = true;
        tigh2 = true;
        bladechap2.y = enemy1rect.y;
        partabblade4 = false;
        bladechap2.x = 28;


    }
    if (bladechap2.y > 0) {
        blade_c = false;
        partabblade4 = true;
    }
    if (partabblade4) {
        bladechap2.y += 6;
        bladechap2.x += 5;
    }


    if (tigh2) {
        if (getTime() % 300 >= 0 && getTime() % 300 < 75)
            showTexture(blade1, bladechap2);
        if (getTime() % 300 >= 75 && getTime() % 300 < 150)
            showTexture(blade2, bladechap2);
        if (getTime() % 300 >= 150 && getTime() % 300 < 225)
            showTexture(blade3, bladechap2);
        if (getTime() % 300 >= 225 && getTime() % 300 < 300)
            showTexture(blade4, bladechap2);
    }
    if (tigh1) {
        if (getTime() % 300 >= 0 && getTime() % 300 < 75)
            showTexture(blade1, bladechap);
        if (getTime() % 300 >= 75 && getTime() % 300 < 150)
            showTexture(blade2, bladechap);
        if (getTime() % 300 >= 150 && getTime() % 300 < 225)
            showTexture(blade3, bladechap);
        if (getTime() % 300 >= 225 && getTime() % 300 < 300)
            showTexture(blade4, bladechap);
    }
    if (tigh3) {
        if (getTime() % 300 >= 0 && getTime() % 300 < 75)
            showTexture(blade1, bladerast);
        if (getTime() % 300 >= 75 && getTime() % 300 < 150)
            showTexture(blade2, bladerast);
        if (getTime() % 300 >= 150 && getTime() % 300 < 225)
            showTexture(blade3, bladerast);
        if (getTime() % 300 >= 225 && getTime() % 300 < 300)
            showTexture(blade4, bladerast);
    }
    if (tigh4) {
        if (getTime() % 300 >= 0 && getTime() % 300 < 75)
            showTexture(blade1, bladerast2);
        if (getTime() % 300 >= 75 && getTime() % 300 < 150)
            showTexture(blade2, bladerast2);
        if (getTime() % 300 >= 150 && getTime() % 300 < 225)
            showTexture(blade3, bladerast2);
        if (getTime() % 300 >= 225 && getTime() % 300 < 300)
            showTexture(blade4, bladerast2);
    }
}
void showscore(){
    showTexture(score,scorerect);
    scoretext=createFontTexture(font,to_string(emtiaz),0,0,0);
    showTexture(scoretext,195,5);
    if(State=='G' && speed==3 && counter%10==0)
    emtiaz++;
}
void showspikes(){
    showTexture(spike,spikes);
    spikes.y+=speed;
    showTexture(spike,0,spikes2,SDL_FLIP_HORIZONTAL);
    spikes2.y+=speed;
    if(spikes.y>500)
        spikes.y=-5000;
    if(spikes2.y>500)
        spikes2.y=-7000;
}
void showbird() {
    if (leftbird.y <= 100) {
        leftbird.y += speed;
    }
    if (leftbird.y > 100) {
        leftbird.x += 6;
        leftbird.y += (speed * 2);
    }
    if (rightbird.y <= 100)
        rightbird.y += speed;
    if (rightbird.y > 100) {
        rightbird.x -= 6;
        rightbird.y += (speed * 2);
    }
    if (rightbird.x < -40) {
        kaftarbarkhord2 = true;
        rightbird.x = 460;
        rightbird.y = -2500;
    }
    if (leftbird.x > 500) {
        kaftarbarkhord = true;
        leftbird.x = 25;
        leftbird.y = -3000;
    }
    if (kaftarbarkhord) {
        if (getTime() % 300 >= 0 && getTime() % 300 < 100)
            showTexture(bird1, leftbird);
        if (getTime() % 300 >= 100 && getTime() % 300 < 200)
            showTexture(bird2, leftbird);
        if (getTime() % 300 >= 200 && getTime() % 300 < 300)
            showTexture(bird3, leftbird);
    }
    if (kaftarbarkhord2) {
        if (getTime() % 300 >= 0 && getTime() % 300 < 100)
            showTexture(bird1, 0, rightbird, SDL_FLIP_HORIZONTAL);
        if (getTime() % 300 >= 100 && getTime() % 300 < 200)
            showTexture(bird2, 0, rightbird, SDL_FLIP_HORIZONTAL);
        if (getTime() % 300 >= 200 && getTime() % 300 < 300)
            showTexture(bird3, 0, rightbird, SDL_FLIP_HORIZONTAL);
    }
    if(hasIntersectionRect(spikes,leftbird))
        leftbird.y-=100;
    if(hasIntersectionRect(spikes2,rightbird))
        rightbird.y-=100;
}
void showshield(){
    shieldrect.y+=speed;
    if(hasIntersectionRect(runleftrect,shieldrect))
        shieldbarkhord=false;
    if(shieldbarkhord)
        showTexture(shield,shieldrect);
    if(shieldrect.y>500){
        shieldbarkhord=true;
        shieldrect.y=-300;
    }
}
void showsanjab(){
    squirrel.y+=speed;
    if(squirrel.y>500) {
        sanjabbarkhord=true;
        squirrel.x=27;
        squirrel.y = -1200;
        x++;
    }
    if(squirrel.x<=27) {
        sanjab = true;
    }
    if(squirrel.x>=403) {
        sanjab = false;
    }
    if(sanjab && x%4!=3 && sanjabbarkhord) {
        squirrel.x+=4;
        if (getTime() % 300 >= 0 && getTime() % 300 < 75)
            showTexture(sl1, squirrel);
        if (getTime() % 300 >= 75 && getTime() % 300 < 150)
            showTexture(sl2, squirrel);
        if (getTime() % 300 >= 150 && getTime() % 300 < 225)
            showTexture(sl3, squirrel);
        if (getTime() % 300 >= 225 && getTime() % 300 < 300)
            showTexture(sl4, squirrel);
    }
    if(!sanjab && x%4!=3 && sanjabbarkhord) {
            squirrel.x -= 4;
            if (getTime() % 300 >= 0 && getTime() % 300 < 75)
                showTexture(sl1,0,squirrel,SDL_FLIP_HORIZONTAL);
            if (getTime() % 300 >= 75 && getTime() % 300 < 150)
                showTexture(sl2, 0,squirrel,SDL_FLIP_HORIZONTAL);
            if (getTime() % 300 >= 150 && getTime() % 300 < 225)
                showTexture(sl3,0,squirrel,SDL_FLIP_HORIZONTAL);
            if (getTime() % 300 >= 225 && getTime() % 300 < 300)
                showTexture(sl4,0,squirrel,SDL_FLIP_HORIZONTAL);

    }
}
void showbakht() {
        speed=-6;
        runleftrect.y +=1;
        if (runleftrect.x <= 220)
            runleftrect.x += 3;
        if (runleftrect.x > 220)
            runleftrect.x -= 3;
        if (getTime() % 300 >= 0 && getTime() % 300 < 100)
            showTexture(nf1, runleftrect);
        if (getTime() % 300 >= 100 && getTime() % 300 < 200)
            showTexture(nf2, runleftrect);
        if (getTime() % 300 >= 200 && getTime() % 300 < 300)
            showTexture(nf3, runleftrect);
        if(runleftrect.y==575)
            playSound(gameover,play);
        if(runleftrect.y>575) {
            speed=0;
            State = 'R';
        }
}
void bakhtan(){
    if(hasIntersectionRect(balcony2,runleftrect) || hasIntersectionRect(balcony,runleftrect)){
        playSound(fall,play);
        state='b';
    }
    if((state=='l' && hasIntersectionRect(squirrel,runleftrect) && x%4!=3) || (state=='r' && hasIntersectionRect(squirrel,runleftrect) && x%4!=3)){
        playSound(fall,play);
        state='b';
    }
    if(hasIntersectionRect(spikes2,runleftrect) || hasIntersectionRect(runleftrect,spikes)) {
        playSound(fall,play);
        state = 'b';
    }
    if((state=='l' && hasIntersectionRect(leftbird,runleftrect)) || (state=='r' && hasIntersectionRect(leftbird,runleftrect))) {
        playSound(fall,play);
        state = 'b';
    }
    if((state=='l' && hasIntersectionRect(rightbird,runleftrect)) || (state=='r' && hasIntersectionRect(rightbird,runleftrect))) {
        playSound(fall,play);
        state = 'b';
    }
    if((state =='l' && hasIntersectionRect(runleftrect,enemy1rect)) || (state=='l' && hasIntersectionRect(runleftrect,bladerast)) || (state=='l' && hasIntersectionRect(runleftrect,bladerast2))) {
        playSound(fall, play);
        state = 'b';
    }
    if((state =='r' && hasIntersectionRect(runleftrect,enemy2rect)) || (state=='r' && hasIntersectionRect(runleftrect,bladechap)) || (state=='r' && hasIntersectionRect(runleftrect,bladechap2))) {
        playSound(fall, play);
        state = 'b';
    }
}
void showrakht() {
    rakht.y+=speed;
    showTexture(rakhtaviz,rakht);
    if(hasIntersectionRect(rakht, balcony))
        balcony.y-=200;
    if(hasIntersectionRect(rakht,balcony2))
        balcony2.y-=200;


    if (rakht.y > 500)
        rakht.y=-1200;
}

void showbalcon() {
    showTexture(balcon, balcony);
    balcony.y += speed;
    if (balcony.y >= 500) {
        balcony.y = -6000;
    }
    showTexture(balcon2, balcony2);
    balcony2.y += speed;
    if (balcony2.y >= 500) {
        balcony2.y = -3000;
    }
    if (abs(balcony.y - balcony2.y) <= 250)
        balcony2.y -= 500;

    if (abs(balcony2.y-spikes.y)<=150)
        balcony2.y-=600;
}
void presskey() {
    if (state == 'l') {
        if (keyPressed(SDL_SCANCODE_SPACE)) {
            playSound(jump,play);
            charkh = true;
            charkh2=false;
            state = 'g';
        }
    }
    if(state=='r'){
        if(keyPressed(SDL_SCANCODE_SPACE)){
            playSound(jump,play);
            charkh=false;
            charkh2=true;
            state='g';
        }
    }
}
void taghyir() {
    if (state=='g' && charkh) {
        if (runleftrect.x >= 40 && runleftrect.x <= 416)
            runleftrect.x += 8;
        if(runleftrect.x<=220)
            runleftrect.y-=1;
        else runleftrect.y+=1;
    }
        if (state=='g' && charkh2) {
            if (runleftrect.x <= 416 && runleftrect.x >= 40)
                runleftrect.x -= 8;
            if(runleftrect.x<=208)
                runleftrect.y+=1;
            else runleftrect.y-=1;
        }

}
void leftrun(){
    if(state=='l') {
        if (getTime() % 300 >= 0 && getTime() % 300 < 75)
            showTexture(nl1, runleftrect);
        if (getTime() % 300 >= 75 && getTime() % 300 < 150)
            showTexture(nl3, runleftrect);
        if (getTime() % 300 >= 150 && getTime() % 300 < 225)
            showTexture(nl2, runleftrect);
        if (getTime() % 300 >= 225 && getTime() % 300 < 300)
            showTexture(nl3, runleftrect);
    }
}
void rightrun(){
    if(state=='r') {
        if (getTime() % 300 >= 0 && getTime() % 300 < 75)
            showTexture(nr1, runleftrect);
        if (getTime() % 300 >= 75 && getTime() % 300 < 150)
            showTexture(nr3, runleftrect);
        if (getTime() % 300 >= 150 && getTime() % 300 < 225)
            showTexture(nr2, runleftrect);
        if (getTime() % 300 >= 225 && getTime() % 300 < 300)
            showTexture(nr3, runleftrect);
    }
}

void showhouse(){
    showTexture(house,houserect);
    houserect.y+=speed;
}
void Background(){
    showTexture(background,back);
}

void showwalls(){
    if(speed==-6){
        if(wallrect.y<-500)
            wallrect.y=500;
        if(wallrect2.y<-500)
            wallrect2.y=500;
        if(wallrect3.y<-500)
            wallrect3.y=500;
        if(wallrect4.y<-500)
            wallrect4.y=500;
        if(wallrect5.y<-500)
            wallrect5.y=500;
        if(wallrect6.y<-500)
            wallrect6.y=500;
    }
    showTexture(walls, wallrect);
    wallrect.y += speed;
    showTexture(walls, wallrect2);
    wallrect2.y += speed;
    showTexture(walls, wallrect3);
    wallrect3.y += speed;
    showTexture(walls, wallrect4);
    wallrect4.y += speed;
    showTexture(walls, wallrect5);
    wallrect5.y += speed;
    showTexture(walls, wallrect6);
    wallrect6.y += speed;
    if(speed==3){
    if (wallrect.y >= 520)
        wallrect.y = -485;
    if (wallrect2.y >= 520)
        wallrect2.y = -485;
    if (wallrect3.y >= 520)
        wallrect3.y = -485;
    if (wallrect4.y >= 520)
        wallrect4.y = -485;
    if (wallrect5.y >= 520)
        wallrect5.y = -485;
    if (wallrect6.y >= 520)
        wallrect6.y = -485;
}

}
void showcharkhesh() {
        if (getTime() % 375 >= 0 && getTime() % 375 < 75)
            showTexture(nj1, runleftrect);
        if (getTime() % 375 >= 75 && getTime() % 375 < 150)
            showTexture(nj2, runleftrect);
        if (getTime() % 375 >= 150 && getTime() % 375 < 225)
            showTexture(nj3, runleftrect);
        if (getTime() % 375 >= 225 && getTime() % 375 < 300)
            showTexture(nj4, runleftrect);
        if (getTime() % 375 >= 300 && getTime() % 375 < 375)
            showTexture(nj5, runleftrect);
        if(runleftrect.x==416 && charkh)
            state='r';
        if(runleftrect.x==40 && charkh2)
            state='l';
}
void emtiazbegir() {
    if (hasIntersectionRect(runleftrect, squirrel) && state == 'g') {
        if (sanjabbarkhord) {
            playSound(rubah, play);
            emtiaz += 100;
            squirrel.x = 700;
        }
        sanjabbarkhord = false;
    }
    if (hasIntersectionRect(runleftrect, leftbird) && state == 'g') {
        if (kaftarbarkhord) {
            playSound(kaftar, play);
            emtiaz += 100;
            leftbird.x = 700;
        }
        kaftarbarkhord = false;
    }
    if (hasIntersectionRect(runleftrect, rightbird) && state == 'g') {
        if (kaftarbarkhord2) {
            playSound(kaftar, play);
            emtiaz += 100;
            rightbird.x = -100;
        }
        kaftarbarkhord2 = false;
    }
    if (hasIntersectionRect(runleftrect, bladechap) && state == 'g') {
        if (tigh1) {
            playSound(star, play);
            emtiaz += 100;
            bladechap.x -= 300;
        }
        tigh1 = false;
    }
    if (hasIntersectionRect(runleftrect, bladechap2) && state == 'g') {
        if (tigh2) {
            playSound(star, play);
            emtiaz += 100;
            bladechap2.x -= 300;
        }
        tigh2 = false;
    }
    if (hasIntersectionRect(runleftrect, bladerast) && state == 'g') {
        if (tigh3) {
            playSound(star, play);
            emtiaz += 100;
            bladerast.x += 300;
        }
        tigh3 = false;
    }
    if (hasIntersectionRect(runleftrect, bladerast2) && state == 'g') {
        if (tigh4) {
            playSound(star, play);
            emtiaz += 100;
            bladerast2.x += 300;
        }
        tigh4 = false;
    }
}
    void showkhatar(){
        if(leftbird.y>-100 && leftbird.y<0)
            showTexture(khatar,khatar1);
        if(rightbird.y>-100 && rightbird.y<0)
            showTexture(khatar,khatar2);

    }

void bazi(){
    if(keyPressed(SDL_SCANCODE_P))
        State='P';
    Background();
    showwalls();


    switch (state) {
        case 'l':leftrun();break;
        case 'g':showcharkhesh();break;
        case 'r':rightrun();break;
        case 'b':showbakht();break;


    }
    showspikes();
    taghyir();
    presskey();
    showrakht();
    bakhtan();
    showsanjab();
    showbalcon();
    showshield();
    showhouse();
    showblade();
    showenemy();
    showbird();

    showscore();
    emtiazbegir();
    showkhatar();
}
void Pause(){
    speed=0;

    showTexture(pause,pauserect);
    showTexture(menu_play,pauseplay);
    showTexture(again,Againrect);
    showTexture(home,Homerect);
    showTexture(seda_on, Seda2);
    if(seda%2==1){
        showTexture(seda_off,Seda2);
    }
    if(mouseInRect(Seda2) && Mouse.clicked()){
        playSound(click,play);
        if(seda%2==1){
            seda2=0;
        }
        seda++;
    }
    showTexture(sound_on,sound1);
    if(play==0) {
        showTexture(seda_off, sound1);
    }
    if(mouseInRect(pauseplay) && Mouse.clicked()) {
        playSound(click,play);
        speed=3;
        State = 'G';
    }
    if(mouseInRect(Againrect) && Mouse.clicked()){
        playSound(click,play);
        emtiaz=0;
        speed=3;
        rect();
        State = 'G';
        state='l';
    }
    if(mouseInRect(Homerect) && Mouse.clicked()){
        playSound(click,play);
        State='m';
    }
    if(mouseInRect(sound1) && Mouse.clicked()){
        if(play==1)
            play=0;
        else if(play==0)
            play=1;
    }
}

int main(int argc, char *argv[])
{
    const int window_width = 500;
    const int window_height = 500;
    SBDL::InitEngine("SBDL Test", window_width, window_height);

    const int FPS =60; //frame per second
    const int delay = 1000 / FPS; //delay we need at each frame
    loadkolli();

    ifstream fin("highscore.txt");
    fin>>high;
    fin.ignore();

    while (SBDL::isRunning()) {
        int startTime = SBDL::getTime();

        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        if(State=='G' || State=='P') {
            if (seda % 2 == 0) {
                seda2++;
                for (int i = 0; i < 1; ++i) {
                    if (seda2 > 1) {
                        break;
                    }


                    playMusic(music, -1);

                }
            } else
                stopMusic();
        } else
            stopMusic();
        counter++;
        //Game logic code
        switch (State){
            case 'm':main_menu();break;
            case 'G':bazi();break;
            case 'R':restart();break;
            case 'P':Pause();break;
        }


        if(emtiaz>high)
            high=emtiaz;
        SBDL::updateRenderScreen();

        int elapsedTime = getTime() - startTime;
        if (elapsedTime < delay)
            SBDL::delay(delay - elapsedTime);

    }
}
