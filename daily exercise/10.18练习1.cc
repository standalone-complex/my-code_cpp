#include <iostream>

using namespace std;

int main(void)
{
    int i = 0;

    //i++ = 0;
    ++i = 0;

    cout << i << endl;

    //将左值截断
    std::move(i);

    return 0;
}