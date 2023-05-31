#include <graphics.h>
#include "snake.h"
#include "food.h"

int main()
{
    initwindow(1320,750,"SNAKE GAME",100,20);
    struct snakeBody body;
    struct POS fruit;
    int length,count=0;
    bool playing=true;
    char lengtharr[3];
    generate(getPosx(), getPosy());
    int page=0;

    //loading screen
    readimagefile("snake2.jpg",500,150,820,300);
    settextstyle(8, HORIZ_DIR, 4);
    outtextxy(500, 320, "LOADING GAME ...");
    rectangle(500,370,820,380);
    setcolor(CYAN);
    for (int a=0;a<=316;a++)
    {
        rectangle(502,372,502+a,378);
        delay(1);
    }
    cleardevice();

    while(1)
    {
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            setcolor(BLUE);

            setfillstyle(SOLID_FILL, BLUE);


            if(GetAsyncKeyState(VK_LEFT))
            {    changeDirTo(LEFT);    }
            if(GetAsyncKeyState(VK_UP))
            {    changeDirTo(UP);      }
            if(GetAsyncKeyState(VK_RIGHT))
            {    changeDirTo(RIGHT);   }
            if(GetAsyncKeyState(VK_DOWN))
            {    changeDirTo(DOWN);    }
            if(GetAsyncKeyState(VK_ESCAPE))
                  break;

            if(playing==true && !update())
            {
                  playing = false;
            }
            drawSnake();


            if(update(getPosx(), getPosy()))
            {
                 generate(getPosx(), getPosy());
                 appendSnake();
            }

            // BORDERS
                 setcolor(WHITE);
                 rectangle(60,60,1260,690);
                 rectangle(55,55,1265,695);
            //OBSTACLES
                setcolor(WHITE);
                setfillstyle(SOLID_FILL,DARKGRAY);
                int obs1[100] = {150,600,150,540,240,540,240,450,360,450,360,600,150,600};
                fillpoly(7,obs1);
                int obs2[100] = {1140,180,1170,180,1170,240,1140,240,1140,180};
                fillpoly(5,obs2);
                int obs3[100] = {750,480,870,480,870,540,840,540,840,510,750,510,750,480};
                fillpoly(7,obs3);

            // SCORE
                 settextstyle(8, HORIZ_DIR, 5);
                 setcolor(GREEN);
                 outtextxy(50, 13, "LENGTH ACHIEVED:");
                 length = getlength();
                 lengtharr[0]=char(48+length/10);
                 lengtharr[1]=char(48+length%10);
                 lengtharr[2]='\0';
                 outtextxy(460, 13, lengtharr);


            // STATUS
                 settextstyle(8, HORIZ_DIR, 5);
                 outtextxy(850, 13, "STATUS:");
                 if (getlength() == 60)
                 {
                      outtextxy(1030, 13, "YOU WON !");
                      playing=false;
                 }
                 else if(playing)
                 {
                      outtextxy(1030, 13, "PLAYING");
                 }
                 else
                 {
                      outtextxy(1030, 13, "GAME OVER");
                 }
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
                 outtextxy(1075,700,"PRESS 'ESC' to EXIT");


            draw();
            page = 1-page;
            delay(100);
    }

    getch();
    closegraph();
}
