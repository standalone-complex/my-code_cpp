#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
  //vector<int> nums{1, 2, 3, 4, 5};
    vector<string> nums{"Hello", "World!"};

  //auto size = count(nums.begin(), nums.end(), 1);
    auto size = count(nums.begin(), nums.end(), "Hello");

    cout << size << endl;

    return 0;
}