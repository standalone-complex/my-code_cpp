#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    /* vector的增长以2的整数幂的形式增长 */
    vector<int> numbers;

    cout << numbers.capacity() << " " << numbers.size() << endl;

    numbers.push_back(0);

    cout << numbers.capacity() << " " << numbers.size() << endl;

    numbers.push_back(0);

    cout << numbers.capacity() << " " << numbers.size() << endl;

    numbers.push_back(0);

    cout << numbers.capacity() << " " << numbers.size() << endl;

    numbers.push_back(0);

    cout << numbers.capacity() << " " << numbers.size() << endl;

    numbers.push_back(0);

    cout << numbers.capacity() << " " << numbers.size() << endl;

    return 0;
}