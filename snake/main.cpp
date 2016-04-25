#include "snake.h"

int main()
{
    Snake * instance = Snake::GetInstance();
    while(1)
    {
       instance->draw(); 
    }
    return 1;
}
