#include "snake.h"

static Snake *_instance = NULL;
Snake * Snake::GetInstance()
{
    if(_instance == NULL)
    {
        _instance = new Snake();
        return _instance;
    }
    else
        return _instance;
}

Snake::Snake()
{
    pos.x = 10;
    pos.y = 10;
    snake_clip.x = 0;
    snake_clip.y = 0;
    snake_clip.width = 50;
    snake_clip.height = 50;
    snake_body.reserve(3);
    init_snake_body();
    srand((int)time(0));
}

void Snake::init_snake_body()
{
    coord pos;
    for(int i = 21;i <= 24;i++)
    {
        pos.x = i;
        pos.y = 15;
        snake_body.push_back(pos);
    }
}

coord Snake::get_ran_pos()
{
    coord tmp_pos;
    while(true)
    {
        tmp_pos.x = random();
        tmp_pos.y = random();
        vector<coord>::iterator itr = find(snake_body.begin(),snake_body.end(),tmp_pos);
        if(itr == snake_body.end())
            continue;
        else
            return tmp_pos;
    }
}

coord Snake::draw()
{
    int x,y;
    for(auto itr : snake_body)
    {
       x = itr->x;
       y = itr->y;
       for(int i = 0;i < y - 1;i++)
       {
           cout << endl;
       }
       for(int i = 0;i < x - 1;i++)
       {
           cout << " ";
       }
       cout << "*";
    }
}
