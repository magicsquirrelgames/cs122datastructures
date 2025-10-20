#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

class DietPlan
{
    public:
        DietPlan();
        DietPlan(const DietPlan &copy);
        ~DietPlan();
        DietPlan &operator= (const DietPlan &rhs);

        const int getGoal() const;
        const string getName() const;
        const string getDate() const;

        void setGoal(int newGoal);
        void setName(string newName);
        void setDate(string newDate);

        void editGoal();

    private:
        int goal;
        string name;
        string date;
};

std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs);

std::istream& operator>> (std::istream& lhs, DietPlan& rhs);