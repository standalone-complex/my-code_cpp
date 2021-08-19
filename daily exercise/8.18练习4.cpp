#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(void)
{   
    list<const char*> lst = {"Hello World!", "Stone Free!", "Dirty Deeds Done Dirt Cheap!"};

    auto i = lst.begin();
    auto j = lst.end();

    vector<string> vtr = {i, j};

    auto i2 = vtr.begin();
    auto j2 = vtr.end();

    while(i2!=j2)
    {
        cout << *i2 << endl;

        i2++;
    }

    return 0;
}