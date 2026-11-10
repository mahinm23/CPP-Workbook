#include <iostream>
#include <string>
using namespace std;

class Order {
    public:
        Order(string s, int q): symb_(s), qty_(q) {}

        void print(){
            cout << "Symbol: " << symb_ << endl;
            cout << "Quantity: " << qty_ << endl;
        };

    protected:
        string symb_;
        int qty_;
};

class LimitOrder : public Order {
    public:
        LimitOrder(string s, int q, double p): Order(s, q), price_(p) {}

        void print(){
            Order::print();
            cout << "Price: "<< price_ << endl;
        };

    private:
        double price_;
};

class MarketOrder : public Order{
    public:
        MarketOrder(string s, int q) : Order(s, q){}
};

int main(){
    LimitOrder o1 = LimitOrder("NVDA", 5, 167.50);
    o1.print();

    MarketOrder o2 = MarketOrder("AAPL", 10);
    o2.print();

    return 0;
}