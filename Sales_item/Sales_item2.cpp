#include "Sales_item.h"

/* 配套data中存有销售记录的文件使用（重定向） */

int main(void)
{
    Sales_item total;

    if(std::cin >> total)
    {
        Sales_item trans;

        while(std::cin >> trans)
        {
            if(trans.isbn() == total.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }

        std::cout << total << std::endl;
    }
    else
    {
        std::cout << "No data!" << std::endl;
    }

    return 0;
}