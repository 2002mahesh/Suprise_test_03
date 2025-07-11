#include<bits/stdc++.h>
#include <list>
#include "ExpenseReport.h"




using namespace std;
int main()
{
   Expense e1,e2,e3;

   e1.type=BREAKFAST;
   e1.amount=20;

   e2.type=DINNER;
   e2.amount=1000;

   e3.type=CAR_RENTAL;
   e3.amount=5000;


   list<Expense>l;
   l.emplace_back(e1);
   l.emplace_back(e2);
   l.emplace_back(e3);
   

   printReport(l);
}