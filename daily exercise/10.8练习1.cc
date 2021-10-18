#include <iostream>
#include <memory>

using namespace std;

int& f(void);

int main(void)
{
    int i = 1;
    //走一个拷贝构造函数
    shared_ptr<int> p(make_shared<int>(1));

    int& c = f();

    cout << c << endl;

    return 0;
}

int& f(void)
{
    int cc = 1;
    int& c = cc;

    return c;
}