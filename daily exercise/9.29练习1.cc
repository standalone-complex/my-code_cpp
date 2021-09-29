#include <iostream>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;

int main(void)
{
    string Aline;

    using_history();

    while(true)
    {
        Aline = readline("enter expression, or q to quit: ");

        if(Aline == "q")
        {
            break;
        }

        add_history(Aline.c_str());
    }

    return 0;
}