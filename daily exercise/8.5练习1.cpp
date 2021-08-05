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
    int t;
    vector<int> numbers;

    while(cin >> t)
    {
        numbers.push_back(t);
    }

    for(auto i : numbers)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}