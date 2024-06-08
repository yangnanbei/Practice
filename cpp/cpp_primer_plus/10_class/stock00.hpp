// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_HPP_
#define STOCK00_HPP_

#include <string.h>

class Stock // class declaration
{
private:
    std::string company;
    long shares;
    double shared_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif /* STOCK00_HPP_ */