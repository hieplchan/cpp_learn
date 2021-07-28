#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

struct Sales_data {
    /* operators member of class Sales_data */
    // const at the end - compiler throw error if this function change member variable of class
    // function defined inside class are implicity inline
    std::string isbn() const { return m_book_no; } 
    Sales_data& combine(const Sales_data&) {} // declare inside class but can be defined elsewhere
    double avg_price() const; // part of implement - not interface

    /* data member of class Sales_data */
    std::string m_book_no;
    unsigned m_units_sold = 0;
    double m_revenue = 0.0;
};

/* nonmember Sales_data interface function */
Sales_data add(const Sales_data &data1, const Sales_data &data2);
std::ostream &print(std::ostream &out_stream, const Sales_data &data);
std::istream &read(std::istream &in_stream, const Sales_data &data);

#endif