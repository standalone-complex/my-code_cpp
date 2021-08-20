#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string frt("Mr.");
    string bck("Ⅲ");
    string name("BBAslayer");

    name.insert(0, frt);
    name.append(bck);

    cout << name << endl;

    return 0;
}