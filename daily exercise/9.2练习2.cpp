#include <iostream>

using namespace std;

int main(void)
{
    size_t v1 = 42;

    auto f = [v1] () mutable { return ++v1; };

    v1 = 0;

    auto j = f();

    cout << v1 << " " << j << endl;

    return 0;
}