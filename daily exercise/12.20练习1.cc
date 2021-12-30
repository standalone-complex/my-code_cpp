#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int* fun(void);

int main(void) {
    int* p = fun();

    cout << *p << endl;
    cout << *p << endl;

    return 0;
}

int* fun(void) {
    int a = 10;

    return &a;
}