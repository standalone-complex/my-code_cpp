#include <iostream>
#include <string>
/* Unicode码测试 */

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
    string buf;
    int* pp;
    int* p;
    const auto it = p;
    /* decltype ~ declare type */
    decltype(it) c = p;

    /* 用了5个字节的emoji */
    /* 没整明白 */
    cout << "😅" << "🐴" << endl;

    cin >> buf;

    cout << buf << endl;

    return 0;
}