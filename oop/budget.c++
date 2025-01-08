 
// Inside the main function create an array of three objects, of type Budget (each object 
// represents a division in the company), then by using for loop enter the values for the data 
// members then print them again by using another for loop.  


#include<iostream>
using namespace std;

class Budget {
    private:
        static double comBudget;
        double divisionBudget;

    public:
        Budget() {
            divisionBudget = 0;
        }

        void addBudget(double amount) {
            comBudget += amount;
            divisionBudget += amount;
        }

        double getDivisionBudget() {
            return divisionBudget;
        }

        static double getComBudget() {
            return comBudget;
        }
};

double Budget::comBudget = 0;

int main() {
   Budget obj[3];
   double amount;
   for (int i = 0; i < 3 ; i++) 
   {
     cout << "Enter budget for division " << i+1 << ": ";
     cin >> amount;
     obj[i].addBudget(amount);
   }

   for (int i = 0; i < 3 ; i++) 
   {
     cout << "Division Budget for division " << i+1 << ": " << obj[i].getDivisionBudget() << endl;
     cout << "Company Budget for division " << i+1 << ": " << obj[i].getComBudget() << endl;
   }
}