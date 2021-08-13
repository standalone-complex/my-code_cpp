#include "Screen.h"

using namespace std;

int main(void)
{
    Screen myScreen(24, 80, 'x');

    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';

    cout << myScreen.size() << endl;

    return 0;
}