#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int main()
{
    double principal_amount,
           monthly_amount,
           interest_rate,
           paid_back,
           interest_paid;
    int    number_of_payments;

    std::cout << "Enter the loan amount: ";
    std::cin >> principal_amount;
    std::cout << "Enter the monthly interest rate as a decimal: ";
    std::cin >> interest_rate;
    std::cout << "Enter the number of payments: ";
    std::cin >> number_of_payments;

    monthly_amount = principal_amount * (interest_rate + (interest_rate / 
        (pow ((1+interest_rate), number_of_payments) - 1)));
    paid_back = monthly_amount * number_of_payments;
    interest_paid = paid_back - principal_amount;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Loan Amount: $ " << principal_amount << std::endl;
    std::cout << "Monthly Interest Rate: " << (interest_rate * 100) << "%" << std::endl;
    std::cout << "Number of Payments: " << number_of_payments << std::endl;
    std::cout << "Monthly Payment: $ " << monthly_amount << std::endl;
    std::cout << "Amount Paid Back: $ " << paid_back << std::endl;
    std::cout << "Interest Paid: $ " << interest_paid << std::endl;
}