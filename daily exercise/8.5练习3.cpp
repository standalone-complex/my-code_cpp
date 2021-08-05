#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void)
{
    int i;
    vector<int> numbers;

    srand((unsigned)time(NULL));

    for(i=1; i<=10; i++)
    {
        numbers.push_back(rand() % 1000);
    }

    cout << "随机生成的10个数字是：" << endl;

    for(auto it = numbers.begin(); it!= numbers.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "翻倍之后的10个数字是：" << endl;

    for(auto it = numbers.begin(); it!=numbers.end(); it++)
    {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}