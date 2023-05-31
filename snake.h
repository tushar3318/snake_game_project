#include <graphics.h>

enum DIR {LEFT , UP , RIGHT , DOWN};

struct POS
{
       int x,y;
       POS()
       {
            x = 90;
            y = 90;
       }
};


struct snakeBody
{

        POS arr[500];            // THIHS ARRAY IS GOING TO CONTAIN THE POSITIONS OF WHOLE SNAKE
        int direction;
        int length;


        snakeBody()
        {
              arr[0].x = 60;        // PROVIDING THE SNAKE ITS INITIAL VALUE
              arr[0].y = 60;
              length = 2;
              direction = RIGHT;
        }
}snakeBody;

void drawSnake()         // DRAWING THE WHOLE SNAKE
{
     for(int i=0; i<snakeBody.length ; i++)
     {
          if(i==0)                                      // DRAWING HEAD
          {
              setcolor(GREEN);
              setfillstyle(SOLID_FILL , GREEN);
              if (snakeBody.direction==LEFT)
              {
                  pieslice(snakeBody.arr[i].x+15,snakeBody.arr[i].y+15,90,270,15);
                  rectangle(snakeBody.arr[i].x+15 , snakeBody.arr[i].y ,snakeBody.arr[i].x+30 , snakeBody.arr[i].y+30);
                  floodfill(snakeBody.arr[i].x+20 , snakeBody.arr[i].y+15 , GREEN);
                  setfillstyle(SOLID_FILL , BLACK);
                  fillellipse(snakeBody.arr[i].x+10,snakeBody.arr[i].y+10, 5, 5);
                  fillellipse(snakeBody.arr[i].x+10,snakeBody.arr[i].y+20, 5, 5);
              }
              if (snakeBody.direction==UP)
              {
                  pieslice(snakeBody.arr[i].x+15,snakeBody.arr[i].y+15,0,180,15);
                  rectangle(snakeBody.arr[i].x , snakeBody.arr[i].y+15 ,snakeBody.arr[i].x+30 , snakeBody.arr[i].y+30);
                  floodfill(snakeBody.arr[i].x+15 , snakeBody.arr[i].y+20 , GREEN);
                  setfillstyle(SOLID_FILL , BLACK);
                  fillellipse(snakeBody.arr[i].x+10,snakeBody.arr[i].y+10, 5, 5);
                  fillellipse(snakeBody.arr[i].x+20,snakeBody.arr[i].y+10, 5, 5);
              }
              if (snakeBody.direction==RIGHT)
              {
                  pieslice(snakeBody.arr[i].x+15,snakeBody.arr[i].y+15,270,90,15);
                  rectangle(snakeBody.arr[i].x , snakeBody.arr[i].y ,snakeBody.arr[i].x+15 , snakeBody.arr[i].y+30);
                  floodfill(snakeBody.arr[i].x+5 , snakeBody.arr[i].y+15 , GREEN);
                   setfillstyle(SOLID_FILL , BLACK);
                  fillellipse(snakeBody.arr[i].x+20,snakeBody.arr[i].y+10, 5, 5);
                  fillellipse(snakeBody.arr[i].x+20,snakeBody.arr[i].y+20, 5, 5);
              }
              if (snakeBody.direction==DOWN)
              {
                  pieslice(snakeBody.arr[i].x+15,snakeBody.arr[i].y+15,180,360,15);
                  rectangle(snakeBody.arr[i].x , snakeBody.arr[i].y ,snakeBody.arr[i].x+30 , snakeBody.arr[i].y+15);
                  floodfill(snakeBody.arr[i].x+15 , snakeBody.arr[i].y+5 , GREEN);
                   setfillstyle(SOLID_FILL , BLACK);
                  fillellipse(snakeBody.arr[i].x+10,snakeBody.arr[i].y+20, 5, 5);
                  fillellipse(snakeBody.arr[i].x+20,snakeBody.arr[i].y+20, 5, 5);
              }
          }

          else
          {
              setcolor(BLUE);
              rectangle(snakeBody.arr[i].x , snakeBody.arr[i].y ,snakeBody.arr[i].x+30 , snakeBody.arr[i].y+30);           // REST OF THE BODY
              setfillstyle(SOLID_FILL , LIGHTGREEN);
              floodfill(snakeBody.arr[i].x+15 , snakeBody.arr[i].y+15 , BLUE);
          }
     }
}

void appendSnake()
{
     if(snakeBody.length < 60)                            // PREVENTS THE LENGTH FROM GOING GREATER THAN 39
        snakeBody.length++;
}

void changeDirTo(int newdir)
{
     if(newdir == LEFT || newdir == RIGHT)
     {
            if(snakeBody.direction == UP || snakeBody.direction == DOWN)
                         snakeBody.direction = newdir;
     }
     else if(newdir == UP || newdir == DOWN)
     {
            if(snakeBody.direction == LEFT || snakeBody.direction == RIGHT)
                         snakeBody.direction = newdir;
     }
}

int obstacle()
{
    if(((1110<snakeBody.arr[0].x)&&(snakeBody.arr[0].x<1170))&&((150<snakeBody.arr[0].y)&&(snakeBody.arr[0].y<240)))
    {
        return 0;
    }
    else if ((((140<snakeBody.arr[0].x)&&(snakeBody.arr[0].x<360))&&((510<snakeBody.arr[0].y)&&(snakeBody.arr[0].y<600)))||(((210<snakeBody.arr[0].x)&&(snakeBody.arr[0].x<360))&&((420<snakeBody.arr[0].y)&&(snakeBody.arr[0].y<540))))
    {
        return 0;
    }
    else if ((((720<snakeBody.arr[0].x)&&(snakeBody.arr[0].x<870))&&((450<snakeBody.arr[0].y)&&(snakeBody.arr[0].y<510)))||(((810<snakeBody.arr[0].x)&&(snakeBody.arr[0].x<870))&&((480<snakeBody.arr[0].y)&&(snakeBody.arr[0].y<540))))
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

int update()
{
     for(int i=1 ; i<snakeBody.length ; ++i)
     {
             if((snakeBody.arr[0].x == snakeBody.arr[i].x && snakeBody.arr[0].y == snakeBody.arr[i].y)||(!obstacle()))
             {
                         return 0;
             }
     }
     for(int i=snakeBody.length ; i>=0 ; --i)
     {
             if(i==0)
             {
                     snakeBody.arr[1].x = snakeBody.arr[0].x;
                     snakeBody.arr[1].y = snakeBody.arr[0].y;
             }
             else
             {
                     snakeBody.arr[i].x = snakeBody.arr[i-1].x;
                     snakeBody.arr[i].y = snakeBody.arr[i-1].y;
             }
     }
     if(snakeBody.direction == LEFT)
     {
                  snakeBody.arr[0].x -= 30;
                  if(snakeBody.arr[0].x == 30)
                  {
                              snakeBody.arr[0].x = 1230;
                  }
     }
     else if(snakeBody.direction == RIGHT)
     {
                  snakeBody.arr[0].x += 30;
                  if(snakeBody.arr[0].x == 1260)
                  {
                              snakeBody.arr[0].x = 60;
                  }
     }
     else if(snakeBody.direction == UP)
     {
                  snakeBody.arr[0].y -= 30;
                  if(snakeBody.arr[0].y == 30)
                  {
                              snakeBody.arr[0].y = 660;
                  }
     }
     else if(snakeBody.direction == DOWN)
     {
                  snakeBody.arr[0].y += 30;
                  if(snakeBody.arr[0].y == 690)
                  {
                              snakeBody.arr[0].y = 60;
                  }
     }
     return 1;
}

int getPosx()
{
    return snakeBody.arr[0].x;
}

int getPosy()
{
    return snakeBody.arr[0].y;
}

int getlength()
{
    return snakeBody.length;
}
