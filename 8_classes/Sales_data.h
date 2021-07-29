#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

struct Sales_data {
    /* operators member of class Sales_data */
    // const at the end - compiler throw error if this function change member variable of class
    // function defined inside class are implicity inline
    std::string isbn() const { return m_book_no; } 
    Sales_data& combine(const Sales_data&); // declare inside class but can be defined elsewhere
    double avg_price() const; // part of implement - not interface

    /* data member of class Sales_data */
    std::string m_book_no;
    unsigned m_units_sold = 0;
    double m_revenue = 0.0;
};

/* nonmember Sales_data interface function */
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

/* Function definition - implementation */

/* member of Sales_data but defined outside of the Class */
double Sales_data::avg_price() const { // must have Sales_data::
    if (m_units_sold) {
        return m_revenue/m_units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &data) {
    m_units_sold += data.m_units_sold;
    m_revenue += data.m_revenue;
    return *this; // return object on which function was call
}

std::istream &read(std::istream &in_stream, Sales_data &item) {
    double price = 0;
    in_stream >> item.m_book_no >> item.m_units_sold >> price;
    item.m_revenue = item.m_units_sold * price;
    return in_stream;
}

std::ostream &print(std::ostream &out_stream, const Sales_data &item) {
    out_stream << item.isbn() << " " << item.m_units_sold << " "
               << item.m_revenue << " " << item.avg_price(); // Let user decide if they need new line or not
    return out_stream;
}

Sales_data add(const Sales_data &item1, const Sales_data &item2) {
    Sales_data sum = item1; // new sum is copy of item1
    sum.combine(item2);
    return sum; // return copy of sum
}

#endif