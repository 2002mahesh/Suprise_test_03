#ifndef LUNCHEXPENSEHANDLER_H
#define LUNCHEXPENSEHANDLER_H

#include "ExpenseTypes.h"
#include <list>
#include <memory>
#include <iostream>
#include <chrono>

class LunchExpenseHandler {
public:
    static void printReportWithLunch(const std::list<std::shared_ptr<ExpenseBase>>& expenses) {
        int total = 0;
        int mealExpenses = 0;
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << "Expenses " << ctime(&now);
        for (const auto& expense : expenses) {
            if (expense->isMeal()) {
                mealExpenses += expense->amount;
            }
            std::string mealOverExpensesMarker = (expense->amount > expense->limit()) ? "X" : " ";
            std::cout << expense->name() << '\t' << expense->amount << '\t' << mealOverExpensesMarker << '\n';
            total += expense->amount;
        }
        std::cout << "Meal expenses: " << mealExpenses << '\n';
        std::cout << "Total expenses: " << total << '\n';
    }
};

#endif
