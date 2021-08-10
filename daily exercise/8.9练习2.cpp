#include <iostream>

int comp(int, int);

int main(void)
{
    int i, j, k ,t;
    
    i = 1;
    j = 2;
    k = 3;
    t = 4;

    printf("%d", comp(i, j));

    return 0;
}

int comp(int a, int b)
{
    return a > b ? a : b;
}