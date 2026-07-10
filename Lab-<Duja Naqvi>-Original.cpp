/*
Name: Duja Naqvi
Lab 4: Savings Account Balance
Original Version
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double starting_balance;
    double annual_interest_rate;
    double deposit_per_month;
    double withdrawal_per_month;
    double monthly_interest;

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

    if (starting_balance < 0)
    {
        cout << "Error: Starting balance cannot be negative." << endl;
        return -1;
    }

    cout << "Enter the number of months that your bank account "
         << "has been open: ";
    cin >> number_of_months;

    updated_balance = starting_balance;

    for (int month = 1; month <= number_of_months; month++)
    {
        cout << "Enter the amount deposited during month "
             << month << ": $";
        cin >> deposit_per_month;

        cout << "Enter the amount withdrawn during month "
             << month << ": $";
        cin >> withdrawal_per_month;

        updated_balance = updated_balance + deposit_per_month;
        updated_balance = updated_balance - withdrawal_per_month;

        total_deposits = total_deposits + deposit_per_month;
        total_withdrawals = total_withdrawals + withdrawal_per_month;

        if (updated_balance < 0)
        {
            cout << "Account closed due to negative balance." << endl;
            return -1;
        }

        monthly_interest =
            (annual_interest_rate / 12.0) * updated_balance;

        total_interest_earned =
            total_interest_earned + monthly_interest;

        updated_balance = updated_balance + monthly_interest;
    }

    cout << fixed << setprecision(2);
    cout << "----------------------------------------------------------------\n";
    cout << left << setw(45)
         << "The ending balance of your account is:"
         << right << "$" << setw(10) << updated_balance << endl;

    cout << left << setw(45)
         << "The total amount you have deposited is:"
         << right << "$" << setw(10) << total_deposits << endl;

    cout << left << setw(45)
         << "The total amount you have withdrawn is:"
         << right << "$" << setw(10) << total_withdrawals << endl;

    cout << left << setw(45)
         << "The total amount of interest earned is:"
         << right << "$" << setw(10) << total_interest_earned << endl;

    return 0;
