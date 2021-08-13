#include "Sales_data.h"

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