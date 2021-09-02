#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    /* 匿名函数lambda，[]中存放它所处函数的局部变量，()中存放函数参数，{}中存放函数块*/
    auto f = [] (int a, int b) { return a + b; };

    cout << f(3, 4) << endl;

    return 0;
}