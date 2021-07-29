#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
    /* function can access class data by make it's friend */
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &s): m_book_no(s) { };
    Sales_data(const std::string &, unsigned, double);
    Sales_data(std::istream &);

    std::string isbn() const { return m_book_no; } 
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;
    
    std::string m_book_no;
    unsigned m_units_sold = 0;
    double m_revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

/* Constructor */
Sales_data::Sales_data(std::istream &in_stream) {
    read(in_stream, *this);
}

Sales_data::Sales_data(const std::string &s, unsigned n, double p)
: m_book_no(s)
, m_units_sold(n)
, m_revenue(n*p)
{
}

/* Member class implementation */
double Sales_data::avg_price() const {
    if (m_units_sold) {
        return m_revenue/m_units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &data) {
    m_units_sold += data.m_units_sold;
    m_revenue += data.m_revenue;
    return *this;
}

std::istream &read(std::istream &in_stream, Sales_data &item) {
    double price = 0;
    in_stream >> item.m_book_no >> item.m_units_sold >> price;
    item.m_revenue = item.m_units_sold * price;
    return in_stream;
}

std::ostream &print(std::ostream &out_stream, const Sales_data &item) {
    out_stream << item.isbn() << " " << item.m_units_sold << " "
               << item.m_revenue << " " << item.avg_price();
    return out_stream;
}

Sales_data add(const Sales_data &item1, const Sales_data &item2) {
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
}

#endif