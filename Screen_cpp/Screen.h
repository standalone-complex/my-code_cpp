#ifndef SCREEN

#define SCREEN

#include <iostream>
#include <string>
#include <vector>

class Screen
{
    public:

        typedef std::string::size_type pos;

        /* 构造函数 */
        Screen() = default;

        /* 这里的cursor是隐式初始化的 */
        Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht*wd, c)
        { }

        /* 成员函数 */
        char get() const {return contents[cursor];} //隐式内联
        char get(pos, pos) const;
        Screen& move(pos, pos);
        Screen& set(char);
        Screen& set(pos, pos, char);

        /* const的重载 解决 item.display(cout).set('#')的问题 */
        /* 通过做出输出和返回的分离解决问题 */

        /* 返回非常量 */
        Screen& display(std::ostream& os)
        {
            do_display(os);

            return *this;
        }

        /* 当对象为const重载这个 返回常量 */
        const Screen& display(std::ostream& os) const
        {
            do_display(os);

            return *this;
        }

    private:

        void do_display(std::ostream& os) const {os << contents;}

        std::string contents;
        pos cursor = 0;
        pos height = 0, width = 0;
    
};

/* 显式内联 */
inline
char Screen::get(pos row, pos column) const
{
    pos t = row * width + column;
    return contents[t];
}

inline
Screen& Screen::move(pos row, pos column)
{
    pos t = row * width + column;

    cursor = t;

    return *this;
}

inline
Screen& Screen::set(char c)
{
    contents[cursor] = c;

    return *this;
}

inline
Screen& Screen::set(pos row, pos column, char c)
{
    pos t = row * width + column;

    contents[t] = c;

    return *this;
}

#endif