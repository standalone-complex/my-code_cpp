#include "Screen.h"

/*  */
using namespace std;

int main(void)
{
    Screen myScreen(5, 5, 'x');

    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';

    myScreen.display(cout);
    cout << '\n';

    return 0;
}