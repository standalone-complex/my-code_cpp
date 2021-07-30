# include <iostream>

int main(void)
{
    int v1, v2;

    std::cout << "Enter two numbers:" << std::endl;

    std::cin >> v1 >> v2;

    std::cout << "The sun of " << v1 << " and " << v2 << " is " << v1+v2 << std::endl;

    return 0;
}