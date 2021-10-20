#include <iostream>

using namespace std;

template <typename... Args>
void g(Args... args)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(args) << endl;

    return;
}

int main(void)
{
    int i(0);

    g(i, i);

    return 0;
}