#include <iostream>

using namespace std;

int comp(int, int);

int main(void)
{
    int i, j, k ,t;
    
    i = 1;
    j = 2;
    k = 3;
    t = 4;

    cout << comp(i, j) << endl;

    return 0;
}

int comp(int a, int b)
{
    return a > b ? a : b;
}