#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

class ExercisePlan
{
    public:
        ExercisePlan();
        ExercisePlan(const ExercisePlan &copy);
        ~ExercisePlan();
        ExercisePlan &operator= (const ExercisePlan &rhs);

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

std::ostream& operator<< (std::ostream& lhs, const ExercisePlan& rhs);

std::istream& operator>> (std::istream& lhs, ExercisePlan& rhs);