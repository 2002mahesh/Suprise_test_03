#include <chrono>
#include <iostream>
#include <iterator>
#include "ExpenseReport.h"

using namespace std;

void printReport(const std::list<Expense>& expenses)
{
    int total = 0;
    int mealExpenses = 0;

    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "Expenses " << ctime(&now);

    for (const auto& expense : expenses) {
        if (expense.type == BREAKFAST || expense.type == DINNER || expense.type == LUNCH) {
            mealExpenses += expense.amount;
        }

        string expenseName = "";
        switch (expense.type) {
        case DINNER:
            expenseName = "Dinner";
            break;
        case BREAKFAST:
            expenseName = "Breakfast";
            break;
        case CAR_RENTAL:
            expenseName = "Car Rental";
            break;
        case LUNCH:
            expenseName = "Lunch";
            break;
        }

        string mealOverExpensesMarker = (expense.type == DINNER && expense.amount > 5000) || (expense.type == BREAKFAST && expense.amount > 1000) || (expense.type == LUNCH && expense.amount > 2000) ? "X" : " ";

        cout << expense.type << '\t' << expense.amount << '\t' << mealOverExpensesMarker << '\n';

        total += expense.amount;
    }

    cout << "Meal expenses: " << mealExpenses << '\n';
    cout << "Total expenses: " << total << '\n';
}
