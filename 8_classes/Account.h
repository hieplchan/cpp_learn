#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static constexpr int period = 30; // static constexpr must defined inside class body
    double daily_tblp[period];
    static double interestRate; // static member exist outdise of object. shared by all Account object
    static double initRate(); // static function do not have *this pointer, not bound to any object
};

// static data meber must be defined outside class body
// like global object - exist until programe completes
void Account::rate(double newRate) {
    interestRate = newRate;
}

double Account::initRate() {
    return 0;
}

double Account::interestRate = initRate();

#endif