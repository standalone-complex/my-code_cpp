#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <memory>
#include <utility>

using namespace std;

void Execute(void);
string Transform(const string&);
int weight(const char);
int calculate(const string&);
void calculate_operater(const string&, stack<int>&);

int main(void)
{
    Execute();

    return 0;
}

void Execute(void)
{
    string Aline;

    while(true)
    {
        cout << "enter expression, or q to quit: " << endl;

        getline(cin, Aline);

        Aline = Transform(Aline);

        if(Aline == "exit")
        {
            cout << "invalid charactor or syntax error!" << endl;
            continue;
        }

        cout << Aline << endl;
        cout << calculate(Aline) << endl;
    }

    return;
}

string Transform(const string& line)
{
    if(line == "q")
    {
        exit(1);
    }

    stack<char> Stack_charactors;
    string ret;
    string num;
    string Aline;
    bool flag(true);
    
    if(line[0] == '-')
    {
        Aline += '0';
    }

    Aline += line + "#";

    //cout << Aline << endl;

    //解析字符串
    for(auto itc = Aline.cbegin(),
        ite = Aline.cend(); ite!=itc; ++itc)
    {
        //空格直接跳过
        if(*itc == ' ')
        {
            continue;
        }
        //如果是数字
        else if(*itc >= '0' && *itc <= '9')
        {
            num += *itc;
            flag = true;
        }
        else
        {
            if(weight(*itc) == -1)
            {
                return "exit";
            }

            if(flag == true)
            {
                ret = ret + num + " ";
                num = "";
            }

            if(Stack_charactors.empty() || (*itc == '('))
            {
                Stack_charactors.push(*itc);
            }
            else if(*itc == ')')
            {
                while(Stack_charactors.top() != '(')
                {
                    ret = ret + Stack_charactors.top() + " ";
                    Stack_charactors.pop();

                    if(Stack_charactors.empty())
                    {
                        return "exit";
                    }
                }
                Stack_charactors.pop();
            }
            else
            {
                while((!Stack_charactors.empty()) && (weight(*itc) <= weight(Stack_charactors.top())))
                {
                    ret  = ret + Stack_charactors.top() + " ";
                    Stack_charactors.pop();
                }

                Stack_charactors.push(*itc);
            }

            flag = false;
        }
    }

    ret.resize(ret.size()-1);
    return ret;
}

int weight(const char sign)
{
    switch(sign)
    {
        case '#':
        {
            return 0;
        }
        case '+':
        {
            return 1;
        }
        case '-':
        {
            return 1;
        }
        case '*':
        {
            return 2;
        }
        case '/':
        {
            return 2;
        }
        case '(':
        {
            return 0;
        }
        case ')':
        {
            return 0;
        }
        default:
        {
            return -1;
        }
    }
}

int calculate(const string& expression)
{
    int ret;
    istringstream is(expression);
    string item;
    stack<int> Stack_nums;

    while(is >> item)
    {
        if((item=="+") || (item=="-") || (item=="*") || (item=="/"))
        {
            calculate_operater(item, Stack_nums);
        }
        else
        {
            Stack_nums.push(atoi(item.c_str()));
        }
    }

    return Stack_nums.top();
}

void calculate_operater(const string& sign, stack<int>& Stack_nums)
{
    int t1, t2;

    if(sign == "+")
    {
        t2 = Stack_nums.top();
        Stack_nums.pop();
        t1 = Stack_nums.top();
        Stack_nums.pop();

        Stack_nums.push(t1 + t2);
    }
    else if(sign == "-")
    {
        t2 = Stack_nums.top();
        Stack_nums.pop();
        t1 = Stack_nums.top();
        Stack_nums.pop();

        Stack_nums.push(t1 - t2);
    }
    else if(sign == "*")
    {
        t2 = Stack_nums.top();
        Stack_nums.pop();
        t1 = Stack_nums.top();
        Stack_nums.pop();

        Stack_nums.push(t1 * t2);
    }
    else
    {
        t2 = Stack_nums.top();
        Stack_nums.pop();
        t1 = Stack_nums.top();
        Stack_nums.pop();

        Stack_nums.push(t1 / t2);
    }

    return;
}