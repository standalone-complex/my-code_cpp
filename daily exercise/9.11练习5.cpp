#include <iostream>

using namespace std;

int main(void)
{
    float male, female;

    cin >> male >> female;

    printf("%.2f%% %.2f%%", (male/(male+female))*100, (female/(male+female))*100);

    return 0;
}