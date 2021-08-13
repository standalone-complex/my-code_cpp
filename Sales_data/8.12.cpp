#include "Sales_data.h"

int main(void)
{
    /* C++Primer这部分和我之间一定有一个沾点啥 */
    /* 为什么习题集在这里给的答案直接是用上class和public了？ */
    /* 给我整麻了属实 */
    /* 我没看漏吧？ */

    Sales_data v1, v2;
    Sales_data& vv1 = v1, &vv2 = v2;

    read(cin, vv1);
    read(cin, vv2);

    print(cout, vv1);
    print(cout, vv2);

    return 0;
}