#include "snake.h"

Snake *Snake::_instance = NULL;
Snake *Snake::GetInstance()
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
    snake_clip.x = 0;
    snake_clip.y = 0;
    snake_clip.width = WIDTH;
    snake_clip.height = HEIGHT;
    snake_body.reserve(3);
    init_snake_body();
    srand((int)time(0));
    update_food_pos();
}
Snake::~Snake()
{
    cout << "end" << endl;
}

void Snake::init_snake_body()
{
    snake_node node; 
    for(int i = 14;i >= 11;i--)
    {
        node.pos.x = i;
        node.pos.y = 15;
        node.direct = RIGHT;
        snake_body.push_back(node);
    }
    ChangeDirection(UP);
}

void Snake::update_food_pos()
{
    snake_node tmp_node;
    while(true)
    {
        tmp_node.pos.x = randomW();
        tmp_node.pos.y = randomH();
        if(tmp_node.pos.x == 0)
            tmp_node.pos.x++;
        if(tmp_node.pos.x == WIDTH - 1)
            tmp_node.pos.x--;
        if(tmp_node.pos.y == 0)
            tmp_node.pos.y++;
        if(tmp_node.pos.y == HEIGHT - 1)
            tmp_node.pos.y--;
        vector<snake_node>::iterator itr = find(snake_body.begin(),snake_body.end(),tmp_node);
        if(itr != snake_body.end())
            continue;
        else
        {
            food_pos = tmp_node.pos;
            return;
        }
    }
}

void Snake::draw()
{
    if(IsHitTheWall())
    {
        cout << "Game Over" << endl;
        return;
    }
    for(int i = 0;i < HEIGHT;i++)
    {
        for(int j = 0;j < WIDTH;j++)
        {
            cout << record_pos[i][j];
        }
        cout << endl;
    }
}

void Snake::set_border()
{
    for(int i = 0;i < WIDTH;i++)
    {
        record_pos[0][i] = '#';
        record_pos[HEIGHT - 1][i] = '#';
    }
    for(int i = 0;i < HEIGHT;i++)
    {
        record_pos[i][0] = '#';
        record_pos[i][WIDTH - 1] = '#';
    }
}

bool Snake::collision_detect()
{
    return(snake_body[0].pos == food_pos);
}

void Snake::update()
{
    if(!IsHitTheWall())
    {
        update_snake_pos();
    }
    memset(record_pos,' ',sizeof(record_pos));
    set_border();
    vector<snake_node>::iterator itr = snake_body.begin();
    for(;itr != snake_body.end();itr++)
    {
        record_pos[itr->pos.y - 1][itr->pos.x - 1] = '*';
    }
    if(collision_detect())
    {
        update_food_pos();
    }
    record_pos[food_pos.y][food_pos.x] = '@';
}

void Snake::update_snake_pos()
{
    for(vector<snake_node>::iterator itr = snake_body.begin();
            itr != snake_body.end();itr++)
    {
        switch(itr->direct)
        {
            case UP: 
                itr->pos.y--;
                break;
            case DOWN:
                itr->pos.y++;
                break;
            case LEFT:
                itr->pos.x--;
                break;
            case RIGHT:
                itr->pos.x++;
                break;
            default:
                break;
        }
    }
    UpdateDirection();
}

bool Snake::IsHitTheWall()
{
    if(snake_body[0].pos.x == 0 || snake_body[0].pos.y == 0 || snake_body[0].pos.x == WIDTH || snake_body[0].pos.y == HEIGHT)
        return true;
    return false;
}

void Snake::UpdateDirection()
{
    vector<snake_node>::reverse_iterator tmp_itr;
    for(vector<snake_node>::reverse_iterator itr = snake_body.rbegin();
            itr != snake_body.rend();itr++)
    {
        tmp_itr = itr;
        tmp_itr++;
        itr->direct = tmp_itr->direct;
    }
}

void Snake::ChangeDirection(direction direct)
{
    snake_body[0].direct = direct;
}
