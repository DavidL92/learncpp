#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

#define random() (rand() % 50)

using namespace std;
typedef struct _coord
{
    int x;
    int y;
   
}coord;

bool operator==(coord& rhs,coord& tmp)
{
    return (tmp.x == rhs.x && tmp.y == rhs.y);
}

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
        void set_coord(coord);
        void add_tail();//add new node to tail when collision
        void init_snake_body();
        bool collision_detect();
        coord get_ran_pos();
        static Snake *GetInstance();
    private:
        Snake();
        vector<coord> snake_body;
        coord pos;
        clip snake_clip;
        static Snake *_instance;
};
