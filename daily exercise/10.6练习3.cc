#include <iostream>

using namespace std;

int main(void)
{
    int n, a, b;

    cin >> n;

    while(cin >> a >> b)
    {
        for(int i=a; i<=b; ++i)
        {
            for(int j=0; j<i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    return 0;
}