#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main(void)
{
    int num1, num2;
    
    while(cin >> num1 >> num2)
    {
        try
        {
            if(num2 == 0)
            {
                throw runtime_error("num2 is 0!");
            }

            cout << (num1 / num2) << endl;
        }
        catch(runtime_error err)
        {
            cout << err.what() << "\nTry again? Enter y or n" << endl;

            char c;

            cin >> c;

            if(c != 'y')
            {
                break;
            }
        }
    }

    return 0;
}