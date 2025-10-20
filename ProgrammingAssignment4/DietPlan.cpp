#include "DietPlan.hpp"

DietPlan::DietPlan()
{
    this->goal = 0;
    this->name = "";
    this->date = "";
}

DietPlan::DietPlan(const DietPlan &copy)
{
    this->goal = copy.goal;
    this->name = copy.name;
    this->date = copy.date;
}

DietPlan::~DietPlan() {}

DietPlan &DietPlan::operator= (const DietPlan &rhs)
{
    this->goal = rhs.goal;
    this->name = rhs.name;
    this->date = rhs.date;

    return *this;
}

const int DietPlan::getGoal() const
{
    return this->goal;
}

const string DietPlan::getName() const
{
    return this->name;
}

const string DietPlan::getDate() const
{
    return this->date;
}

void DietPlan::setGoal(int newGoal)
{
    this->goal = newGoal;
    if(goal < 0) goal = 0;
}

void DietPlan::setName(string newName)
{
    this->name = newName;
}

void DietPlan::setDate(string newDate)
{
    this->date = newDate;
}

void DietPlan::editGoal()
{
    int newGoal = 0;

    cout << "What would you like to change the goal for " << this->date << " to?: ";
    
    cin >> newGoal;
    setGoal(newGoal);

    cout << "Goal updated.\n";
}

std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs)
{
    lhs << rhs.getName() << std::endl << rhs.getGoal() << std::endl << rhs.getDate() << std::endl;
    return lhs;
}

std::istream& operator>> (std::istream& lhs, DietPlan& rhs)
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