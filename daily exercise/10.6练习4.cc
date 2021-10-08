#include <iostream>

using namespace std;

int max(int, int);
int min(int, int);

int main(void)
{
    int a, b;
    bool flag(true);

    while(cin >> a >> b)
    {
        if(flag)
        {
            flag = false;
        }
        else
        {
            cout << endl;
        }

        cout << max(a, b) << " " << min(a, b) << flush;
    }

    return 0;
}

int max(int a, int b)
{
    int c = a % b;

    while(c != 0)
    {
        a = b;
        b = c;
        
        c = a % b;
    }

    return b;
}

int min(int a, int b)
{
    return (a*b) / max(a, b);
}