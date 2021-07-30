#include <iostream>

int main(void)
{
    int value, sum;

    value = 0;
    sum = 0;

    std::cout << "Enter some numbers:" << std::endl;

    /* 在Windows系统中，文件结束符为Ctrl+Z然后按Enter或者Return键 */
    /* 在类UNIX系统中， 文件结束符为Ctrl+D */
    while(std::cin >> value)
    {
        sum += value;
    }

    std::cout << "\nValues' sum is: " << sum << std::endl;

    return 0;
}