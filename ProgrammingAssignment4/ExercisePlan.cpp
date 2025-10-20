#include "ExercisePlan.hpp"

ExercisePlan::ExercisePlan()
{
    this->goal = 0;
    this->name = "";
    this->date = "";
}

ExercisePlan::ExercisePlan(const ExercisePlan &copy)
{
    this->goal = copy.goal;
    this->name = copy.name;
    this->date = copy.date;
}

ExercisePlan::~ExercisePlan() {}

ExercisePlan &ExercisePlan::operator= (const ExercisePlan &rhs)
{
    this->goal = rhs.goal;
    this->name = rhs.name;
    this->date = rhs.date;

    return *this;
}

const int ExercisePlan::getGoal() const
{
    return this->goal;
}

const string ExercisePlan::getName() const
{
    return this->name;
}

const string ExercisePlan::getDate() const
{
    return this->date;
}

void ExercisePlan::setGoal(int newGoal)
{
    this->goal = newGoal;
    if(goal < 0) goal = 0;
}

void ExercisePlan::setName(string newName)
{
    this->name = newName;
}

void ExercisePlan::setDate(string newDate)
{
    this->date = newDate;
}

void ExercisePlan::editGoal()
{
    int newGoal = 0;

    cout << "What would you like to change the goal for " << this->date << " to?: ";
    
    cin >> newGoal;
    setGoal(newGoal);

    cout << "Goal updated.\n";
}

std::ostream& operator<< (std::ostream& lhs, const ExercisePlan& rhs)
{
    lhs << rhs.getName() << std::endl << rhs.getGoal() << std::endl << rhs.getDate() << std::endl;
    return lhs;
}

std::istream& operator>> (std::istream& lhs, ExercisePlan& rhs)
{
    string newName;
    int newGoal;
    string newDate;

    lhs >> newName;
    lhs >> newGoal;
    lhs >> newDate;

    rhs.setName(newName);
    rhs.setGoal(newGoal);
    rhs.setDate(newDate);

    return lhs;
}