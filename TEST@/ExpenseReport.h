#ifndef EXPENSEREPORT_H
#define EXPENSEREPORT_H

#include <list>
#include <map>
#include <string>

using namespace std;

enum Type
{
    BREAKFAST, DINNER, CAR_RENTAL,LUNCH
};

class Expense
{
    public:
    
    Type type;
    int amount;
};

extern void printReport(const std::list<Expense>& expenses);

#endif
