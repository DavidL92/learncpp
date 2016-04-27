#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <unistd.h>
#include <curses.h>

#define WIDTH 40
#define HEIGHT 30

#define randomW() (rand() % WIDTH)
#define randomH() (rand() % HEIGHT)

using namespace std;

typedef enum _direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}direction;
typedef struct _coord
{
    int x;
    int y;
    bool operator==(const _coord& rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }
}coord;

typedef struct _snake_node 
{
    coord pos;
    direction direct;
    bool operator==(const _snake_node& rhs) const
    {
        return (pos == rhs.pos && pos == rhs.pos);
    }
}snake_node;

typedef struct _clip
{
    int x;
    int y;
    int width;
    int height;
}clip;

class Snake
{
    public:
        ~Snake();
        void draw();
        void update_snake_pos();
        void update();
        void set_coord(coord);
        void add_tail();//add new node to tail when collision
        void init_snake_body();
        bool collision_detect();
        bool IsHitTheWall();
        bool IsHitBody();
        void UpdateDirection();
        void set_border();
        void update_food_pos();
        void ChangeDirection(direction);
        static Snake *GetInstance();
    private:
        Snake();
        vector<snake_node> snake_body;
        coord food_pos;
        clip snake_clip;
        static Snake *_instance;
        char record_pos[HEIGHT][WIDTH];
};
