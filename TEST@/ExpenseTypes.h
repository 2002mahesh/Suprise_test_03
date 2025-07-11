#ifndef EXPENSETYPES_H
#define EXPENSETYPES_H

#include <string>
#include <list>
#include <iostream>
#include <chrono>

class ExpenseBase {
public:
    int amount;
    virtual std::string name() const = 0;
    virtual int limit() const = 0;
    virtual bool isMeal() const { return false; }
    virtual ~ExpenseBase() {}
};

class BreakfastExpense : public ExpenseBase {
public:
    std::string name()  { return "Breakfast"; }
    int limit()  { return 1000; }
    bool isMeal() { return true; }
};

class DinnerExpense : public ExpenseBase {
public:
    std::string name()  { return "Dinner"; }
    int limit()  { return 5000; }
    bool isMeal()  { return true; }
};

class LunchExpense : public ExpenseBase {
public:
    std::string name()  { return "Lunch"; }
    int limit()  { return 2000; }
    bool isMeal()  { return true; }
};

class CarRentalExpense : public ExpenseBase {
public:
    std::string name()  { return "Car Rental"; }
    int limit()  { return INT_MAX; }
};

#endif
