#include <graphics.h>
#include <ctime>
struct POS foodPos;

void draw()                       // DRAW THE FOOD
{
     setcolor(RED);
     circle(foodPos.x+15, foodPos.y+15,14.5);
     setfillstyle(SOLID_FILL, RED);
     floodfill(foodPos.x+15, foodPos.y+15, RED);
}

void generate(int snakeHeadx, int snakeHeady)     // GENERATE NEW POSITION FOR THE PARTICLE
{
     srand(time(0));
     foodPos.x = 30*(rand()%40 + 2);
     srand(time(0));
     foodPos.y = 30*(rand()%21 + 2);
     if ((foodPos.x == snakeHeadx && foodPos.y == snakeHeady))
        {generate(snakeHeadx, snakeHeady);}
     else if ((((140<foodPos.x)&&(foodPos.x<360))&&((510<foodPos.y)&&(foodPos.y<600)))||(((210<foodPos.x)&&(foodPos.x<360))&&((420<foodPos.y)&&(foodPos.y<540))))
     {
         generate(snakeHeadx, snakeHeady);
     }
     else if(((1110<foodPos.x)&&(foodPos.x<1170))&&((150<foodPos.y)&&(foodPos.y<240)))
     {
         generate(snakeHeadx, snakeHeady);
     }
     else if((((720<foodPos.x)&&(foodPos.x<870))&&((450<foodPos.y)&&(foodPos.y<510)))||(((810<foodPos.x)&&(foodPos.x<870))&&((480<foodPos.y)&&(foodPos.y<540))))
     {
         generate(snakeHeadx, snakeHeady);
     }
}

bool update(int snakeHeadx, int snakeHeady)       // GIVE US THE STATUS OF FOOD
{
     if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
          return true;
     else
          return false;
}
