#include <iostream>

using namespace std;

int main(void)
{
    int n, sum(0);

    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }

        for(int i=0; i<=n; ++i)
        {
            if(i%2 == 1)
            {
                sum += i;
            }
        }

        cout << sum << endl;
        sum = 0;
    }

    return 0;
}