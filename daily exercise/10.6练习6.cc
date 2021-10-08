#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    int n, day;
    double guo(100), wang(100);

    cin >> n;

    for(int i=0; i<n; ++i)
    {
        guo *= 1.01;

        day = i % 5;

        if(day>=3)
        {
            wang *= 0.99;
        }
        else
        {
            wang *= 1.02;
        }
    }

    cout << fixed << setprecision(5) <<  guo << "," << wang << flush;

    return 0;
}