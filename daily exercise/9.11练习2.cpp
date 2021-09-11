#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    bool flag = true;
    const float PI = 3.1415926;
    float R;
    vector<float> vf;

    while(cin >> R)
    {
        R = (4 * PI * pow(R, 3)) / 3;

        vf.push_back(R);
    }

    for(auto i: vf)
    {
        if(flag == true)
        {
            flag = false;
        }
        else
        {
            cout << endl;
        }

        printf("%.3f", i);
    }

    return 0;
}