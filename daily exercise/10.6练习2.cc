#include <iostream>

using namespace std;

long long f(long long );
long long C(long long , long long );

int main(void)
{
    long long n;

    while(cin >> n)
    {
        cout << f(n) << endl;
    }

    return 0;
}

long long f(long long n)
{
    if(n == 1)
    {
        return 1;
    }

    return C(2*n, n) - C(2*n, n-1);
}

long long C(long long m, long long n)
{
    long long mm = 1, nn = 1;

    for(long long i=0; i<n; ++i)
    {
        mm *= (m-i);
        nn *= (n-i);
    }

    return mm / nn;
}