#include "Screen.h"

using namespace std;

int main(void)
{
    Screen myScreen;
    //Window_mgr myWindow_mgr;

    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';

    cout << myScreen.size() << endl;

    return 0;
}