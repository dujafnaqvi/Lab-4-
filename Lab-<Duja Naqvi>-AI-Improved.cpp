/*
Name: Duja Naqvi
Lab 4: Savings Account Balance
AI-Improved Version
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double starting_balance = 0.0;
    double annual_interest_rate = 0.0;
    double updated_balance = 0.0;
    double total_deposits = 0.0;
    double total_withdrawals = 0.0;
    double total_interest_earned = 0.0;
    int number_of_months = 0;

    cout << "Enter the annual interest rate as a decimal "
         << "(e.g., 0.05 for 5%): ";
    cin >> annual_interest_rate;

    cout << "Enter the starting balance of your account: $";
    cin >> starting_balance;

    if (!cin || annual_interest_rate < 0.0 || starting_balance < 0.0)
    {
        cout << "Error: Enter a valid nonnegative interest rate "
             << "and starting balance.\n";
        return -1;
    }

    cout << "Enter the number of months that your bank account "
         << "has been open: ";
    cin >> number_of_months;

    if (!cin || number_of_months <= 0)
    {
        cout << "Error: Number of months must be greater than zero.\n";
        return -1;
    }

    updated_balance = starting_balance;
    const double monthly_interest_rate = annual_interest_rate / 12.0;

    for (int month = 1; month <= number_of_months; ++month)
    {
        double monthly_deposit = 0.0;
        double monthly_withdrawal = 0.0;

        cout << "Enter the amount deposited during month "
             << month << ": $";
        cin >> monthly_deposit;

        cout << "Enter the amount withdrawn during month "
             << month << ": $";
        cin >> monthly_withdrawal;

        if (!cin || monthly_deposit < 0.0 || monthly_withdrawal < 0.0)
        {
            cout << "Error: Deposits and withdrawals must be "
                 << "nonnegative numbers.\n";
            return -1;
        }

        updated_balance += monthly_deposit;
        updated_balance -= monthly_withdrawal;

        total_deposits += monthly_deposit;
        total_withdrawals += monthly_withdrawal;

        if (updated_balance < 0.0)
        {
            cout << "Account closed due to negative balance.\n";
            return -1;
        }

        const double monthly_interest =
            monthly_interest_rate * updated_balance;

        total_interest_earned += monthly_interest;
        updated_balance += monthly_interest;
    }

    cout << fixed << setprecision(2);
    cout << "----------------------------------------------------------------\n";
    cout << left << setw(45)
         << "The ending balance of your account is:"
         << right << "$" << setw(10) << updated_balance << '\n';

    cout << left << setw(45)
         << "The total amount you have deposited is:"
         << right << "$" << setw(10) << total_deposits << '\n';

    cout << left << setw(45)
         << "The total amount you have withdrawn is:"
         << right << "$" << setw(10) << total_withdrawals << '\n';

    cout << left << setw(45)
         << "The total amount of interest earned is:"
         << right << "$" << setw(10) << total_interest_earned << '\n';

    return 0;
}
