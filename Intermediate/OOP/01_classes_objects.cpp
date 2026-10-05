#include <iostream>

// classes need to be written as public so that their variables can be seen in other places

class Order {
public:
    std::string symbol;
    double price;
    int quantity;

    void print() {
        std::cout << symbol << " " << quantity << " @ " << price << "\n";
    }
};

/*
int main() {
    Order o;
    o.symbol = "AAPL";
    o.price = 150.5;
    o.quantity = 100;
    o.print();
}
*/


/*
Exercise 1:

Write a class called Trade with members std::string side (e.g. "BUY" or "SELL"), double price, and int quantity. 
Give it a member function double notional() that returns price * quantity. 
Write a small main() that creates a Trade, sets its fields, and prints the result of notional().
*/

class Trade {
    public: 
        std::string Side;
        double Price;
        int Quantity;

        Trade(std::string side, double price, int quantity){
            Side = side;
            Price = price;
            Quantity = quantity;
            }

        void print() {
            std::cout << Side << " " << Quantity << " units @" << Price << std::endl;
        }

        double notional(){
            double res = Price * Quantity;
            std::cout << Price << " * " << Quantity << " = " << res << std::endl;
            return res;
        }

};

int main(){
    Trade trade1 = Trade("BUY", 12.5, 10);
    trade1.print();
    double amount1 = trade1.notional();

    return 0;
}