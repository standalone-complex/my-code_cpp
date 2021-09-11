#include <iostream>

using namespace std;

int main(void)
{
    int num1, num2;

    cin >> num1 >> num2;

    cout << num1;

    if(num2 >= 0)
    {
        cout << " + " << num2;
    }
    else
    {
        cout << " - " << abs(num2);
    }

    cout << " = " << num1+num2;

    return 0;
}