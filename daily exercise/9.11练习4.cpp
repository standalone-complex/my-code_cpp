#include <iostream>

using namespace std;

int main(void)
{
    int hour1, min1, hour2, min2;

    cin >> hour1 >> min1 >> hour2 >> min2;

    hour2--;
    min2 += 60;

    hour2 -= hour1;
    min2 -= min1;

    printf("%.2d:%.2d", hour2, min2);

    return 0;
}