#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");
    vector<int> nums;

    //输入
    while(in != eof)
    {
        nums.push_back(*(in++));
    }

    sort(nums.begin(), nums.end());

    //打印不重复元素
    unique_copy(nums.begin(), nums.end(), out);

    return 0;
}