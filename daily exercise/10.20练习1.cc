#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main(void) {
    static default_random_engine s(time(0));
    static uniform_int_distribution<unsigned> u(0, 100);

    cout << s.min() << " " << s.max() << endl;

    for(int i=0; i<10; ++i) {
        //pseudo random
        cout << u(s) << endl;
    }

    return 0;
}