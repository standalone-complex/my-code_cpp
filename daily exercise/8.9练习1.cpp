#include <iostream>

using namespace std;

void fun(void);

int main(void)
{
    void (*p)(void) = fun;

    cout << p << " " << fun << endl;

    return 0;
}

void fun(void){}