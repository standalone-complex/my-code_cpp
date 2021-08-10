#include <iostream>
#include "Sales_data.h"

using namespace std;

int main(void)
{
    cout << "请输入交易记录（ISBN、销售量、原价、实际售价）：" << endl;

    /* 对于C++,未typedef的结构体也可以直接使用struct后的内容当做数据类型来直接使用 */
    Sales_data total;

    if(cin >> total)
    {
        Sales_data trans;

        while(cin >> trans)
        {
            if(trans.isbn() == total.isbn())
            {
                total += trans;
            }
            else
            {
                cout << total << endl;

                total = trans;
            }
        }

        cout << total << endl;
    }
    else
    {
        cout << "No data!" << endl;
        return -1;
    }

    return 0;
}