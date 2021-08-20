#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string src("ab2c3d7R4E6");
    string flag_number("0123456789");
    string flag_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    auto pos = 0;

    /* 将find_first_of()换成find_first_not_of()，同时将flag_number和flag_alphabet的位置对调，函数的效果不变 */
    while((pos=src.find_first_of(flag_number, pos)) != src.npos)
    {
        cout << "index:" << pos << " " << "item:" << src[pos] << endl;

        pos++;
    }

    pos = 0;

    while((pos=src.find_first_of(flag_alphabet, pos)) != src.npos)
    {
        cout << "index:" << pos << " " << "item:" << src[pos] << endl;

        pos++;
    }

    return 0;
}