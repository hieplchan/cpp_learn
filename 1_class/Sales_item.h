#include <string>
#include <iostream>

class Sales_item {
public:

    std::string bookNo;
    double revenue = 0.0;
    unsigned units_sold = 0;

    std::string isbn() {
        return bookNo;
    }

    friend std::istream& operator>>(std::istream& in, Sales_item& item) {
        double price;
        in >> item.bookNo >> item.units_sold >> price;
        item.revenue = item.units_sold*price;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Sales_item& item) {
        out << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.revenue/item.units_sold;
        return out;
    }

    Sales_item& operator+=(Sales_item& right_item) {
        revenue += right_item.revenue;
        units_sold += right_item.units_sold;
        return *this;
    }

    Sales_item& operator==(Sales_item& right_item) {
        revenue = right_item.revenue;
        units_sold = right_item.units_sold;
        return *this;
    }

    friend Sales_item operator+(Sales_item& left_item, Sales_item& right_item) {
        Sales_item ret(left_item);
        ret += right_item;
        return ret;
    }
};

