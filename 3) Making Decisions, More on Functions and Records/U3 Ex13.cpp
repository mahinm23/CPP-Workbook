#include <iostream>
#include <iomanip>

int main() {

    float initial_income;
    float income;
    float initial_allowance = 12750;
    float basic_tax = 0.20;
    float secondary_allowance = 50270;
    float higher_rate = 0.4;
    float higher_allowance = 125140;
    float additional_rate = 0.45;
    float tax;

    std::cout << "Please enter your income" << std::endl;
    std::cin >> income;

    initial_allowance = income;
    
    if (initial_income >= initial_allowance) {
        tax = (income-initial_allowance)*basic_tax;
        income = initial_income - initial_allowance;

        if (initial_income >= secondary_allowance) {
            tax = tax + (income-secondary_allowance)*higher_rate;
            income = initial_income - secondary_allowance;

            if (initial_income >= higher_allowance) {
                tax = tax + (income-higher_allowance)*additional_rate;
            }
        }
    } 

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your tax is: " << tax << std::endl;

    return 0;
}