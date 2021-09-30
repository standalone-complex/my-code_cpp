#include <iostream>
#include <fstream>
#include <stack>
#include "WordQuery.hh"
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;

void Execute(TextQuery&);
string Transform(const string&);
Query calculate(const string&);
int weight(const char);
void calculate_operater(const string&, stack<Query>&);

bool Error(false);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Error format!" << endl;
        exit(1);
    }

    ifstream in(argv[1]);

    if(!in)
    {
        cout << "Open file error!" << endl;
        exit(1);
    }

    TextQuery TQ(in);

    Execute(TQ);

    return 0;
}

void Execute(TextQuery& TQ)
{
    string Aline;
    //Query res;

    using_history();

    while(true)
    {
        Aline = readline("enter experssion, or q to quit: ");
        Aline = Transform(Aline);

        if(Error)
        {
            cout << "invalid charactor or syntax error!" << endl;
            add_history(Aline.c_str());
            Error = false;
            continue;
        }

        if(Aline == "")
        {
            continue;
        }

        Query res(calculate(Aline));

        if(Error)
        {
            cout << "invalid charactor or syntax error!" << endl;
            add_history(Aline.c_str());
            Error = false;
            continue;
        }

        print(cout, res.eval(TQ)) << endl;
    }

    return;
}

string Transform(const string& line)
{
    if(line == "q")
    {
        exit(1);
    }

    add_history(line.c_str());

    stack<char> Stack_charactors;
    string ret;
    string num;
    string Aline;
    bool flag(true);

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
        //如果是单词
        else if((*itc >= 'a' && *itc <= 'z') || (*itc >= 'A' && *itc <= 'Z'))
        {
            num += *itc;
            flag = true;
        }
        else
        {
            if(weight(*itc) == -1)
            {
                Error = true;
                return "";
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
                        Error = true;
                        return "";
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
        case '|':
        {
            return 1;
        }
        case '&':
        {
            return 1;
        }
        case '~':
        {
            return 1;
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

Query calculate(const string& expression)
{
    int ret;
    istringstream is(expression);
    string item;
    stack<Query> Stack_nums;

    while(is >> item)
    {
        if((item=="|") || (item=="&") || (item=="~"))
        {
            calculate_operater(item, Stack_nums);

            if(Error)
            {
                return Query("");
            }
        }
        else
        {
            Stack_nums.push(Query(item));
        }
    }

    return Stack_nums.top();
}

void calculate_operater(const string& sign, stack<Query>& Stack_nums)
{
    //Query t1, t2;

    if(sign == "|")
    {
        if(Stack_nums.size() < 2)
        {
            Error = true;
            return;
        }

        Query t2(Stack_nums.top());
        Stack_nums.pop();
        Query t1(Stack_nums.top());
        Stack_nums.pop();

        Stack_nums.push(t1 | t2);
    }
    else if(sign == "&")
    {
        if(Stack_nums.size() < 2)
        {
            Error = true;
            return;
        }

        Query t2(Stack_nums.top());
        Stack_nums.pop();
        Query t1(Stack_nums.top());
        Stack_nums.pop();

        Stack_nums.push(t1 & t2);
    }
    else if(sign == "~")
    {
        if(Stack_nums.size() < 1)
        {
            Error = true;
            return;
        }

        Query t1(Stack_nums.top());
        Stack_nums.pop();

        Stack_nums.push(~t1);
    }

    return;
}