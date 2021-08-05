#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::oct;

int main(void)
{
    unsigned char i(0b01110001);

    cout << oct << i << endl;

    return 0;
}