#include <iostream>

using namespace std;

int main(void)
{
    char c;
    int n, i, j;

    cin >> c >> n;

    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
        {
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}