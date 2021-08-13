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

#endif