#include <iostream>

using namespace std;

void f();

int main(int argc, char* argv[])
{
    

    cout << argc << " " << *argv << endl;

    return 0;
}

void f(void)
{
    cout << "Hello!" << flush;

    return;
}