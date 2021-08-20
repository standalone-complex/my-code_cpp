#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string name("r2d2");
    string numbers("0123456789");

    auto pos = numbers.find(name);

    /* npos等于任何string最大的可能大小 */
    cout << pos << " " << numbers.npos << endl;

    return 0;
}