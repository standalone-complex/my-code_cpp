#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    float num;
    vector<float> vf;
    

    while(cin >> num)
    {
        num = (sqrt(3)/4) * num * num;

        vf.push_back(num);

        //这个函数是保留有效数字不是保留多少位小数
        //cout << setprecision(2) << num << endl;
    }

    for(auto i: vf)
    {
        printf("%.2f\n", i);
    }

    return 0;
}