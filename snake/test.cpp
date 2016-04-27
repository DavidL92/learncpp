#include <iostream>
#include <curses.h>
using namespace std;
int main()
{
    initscr();
    cout << "###################" << endl;
    getch();

    endwin();
    return 1;
}
