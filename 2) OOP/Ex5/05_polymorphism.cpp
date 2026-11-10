#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Order{
    public:
        Order(string s, int q): sym_(s), qty_(q) {}

        virtual void print(){
            cout << "Symbol: " << sym_ << endl;
            cout << "Quantity: " << qty_ << endl;
        }

        virtual ~Order() {}

    protected:
        string sym_;
        int qty_;
};

class LimitOrder : public Order{
    public:
        LimitOrder(string s, int q, double p) : Order(s, q), prc_(p) {};

        void print() override {
            Order::print();
            cout << "Price: " << prc_ << endl;
        }

    private:
        double prc_;
};

class MarketOrder : public Order{
    public:
        MarketOrder(string s, int q) : Order(s, q) {}

        void print() override { Order::print(); }
};

int main(){
    vector<Order*> orders;
    orders.push_back(new LimitOrder("NVDA", 5, 167.00));
    orders.push_back(new MarketOrder("NVDA", 5));

    for (Order* o : orders){
        o->print();
    }

    for (Order* o : orders){
        delete o;
    }

    return 0;
}