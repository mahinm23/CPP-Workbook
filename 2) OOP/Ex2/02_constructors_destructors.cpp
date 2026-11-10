#include <iostream>

class Trade {
    public:
        std::string side;
        double price;
        int quantity;

        Trade(std::string s, double p, int q): side(s), price(p), quantity(q) {}

        void print() {
            std::cout << side << " " << quantity << " units @" << price << std::endl;
        }

        double notional(){
            double res = price * quantity;
            std::cout << price << " * " << quantity << " = " << res << std::endl;
            return res;
        }

};

int main(){
    Trade trade1 = Trade("BUY", 12.5, 10);
    trade1.print();
    double amount1 = trade1.notional();

    return 0;
}


