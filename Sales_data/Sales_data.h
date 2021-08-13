#ifndef SALES_DATA_H

#define SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;

struct Sales_data
{
    /* 构造函数属实是没给我整明白 */
    
    /* 这三个好像是直接定义了 */
    Sales_data() = default;
    Sales_data(const std::string& s) : bookNo(s) { }
    Sales_data( const std::string& s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p*n) { }
    
    /* 这是一个声明 */
    Sales_data (std::istream&);
    
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;

    /* 中间的const是修改隐式this指针的类型 */
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::istream& read(std::istream&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    /* 返回左值 */
    return *this;
}

double Sales_data::avg_price() const
{
    if(units_sold != 0)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

istream& read(istream& is, Sales_data& item)
{
    double price = 0;

    is >> item.bookNo >> item.units_sold >> price;

    item.revenue = price * item.units_sold;

    return is;
}

ostream& print(ostream& os, Sales_data& item)
{
    os  << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price() << endl;

    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
    /* 可以这么写的吗？？？ */
    Sales_data sum = lhs;
    sum.combine(rhs);

    return sum;
}

/* 给我整不会了 */
Sales_data::Sales_data(std::istream& is)
{
    read(is, *this);
}

#endif