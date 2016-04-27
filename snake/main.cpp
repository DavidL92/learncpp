#include "snake.h"

int main()
{
    Snake * instance = Snake::GetInstance();
    while(1)
    {
        instance->update();
        instance->draw(); 
        sleep(1);
    }
    return 1;
}
