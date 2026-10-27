#include <iostream>

// classes need to be written as public so that their variables can be seen in other places

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