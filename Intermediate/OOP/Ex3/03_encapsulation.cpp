#include <iostream>
#include <string>
using namespace std;

class Order {
    public:
        Order(string s, double p, int q) : symbol(s), price(p), quantity(0) {
            setQuantity(q);
        }
        string getSymbol() const { return symbol; }
        double getPrice() const { return price; }
        int getQuantity() const { return quantity; }
        void setQuantity(int q){
            if (q>0){
                quantity = q;
            } else {
                cout << "Error, had to be positive" << endl;
            }
        }
    private:
        string symbol;
        double price;
        int quantity;
};

int main() {
    Order o1 = Order("NVDA", 115, 10);
    cout << "symb " << o1.getSymbol() << endl;
    cout << "price " << o1.getPrice() << endl;
    cout << "quantity " << o1.getQuantity() << endl;
    o1.setQuantity(-5);
    return 0;
}