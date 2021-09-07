#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void input(vector<int>*, istream&);
void output(vector<int>*, ostream&);

int main(void)
{
    auto p(new vector<int>);

    input(p, cin);

    output(p, cout);

    delete p;

    return 0;
}

void input(vector<int>* p, istream& is)
{
    int num;

    while(is >> num)
    {
        p->push_back(num);
    }

    return;
}

void output(vector<int>* p, ostream& os)
{
    auto i = p->cbegin();
    auto j = p->cend();

    while(i != j)
    {
        cout << *i << endl;

        i++;
    }

    return;
}