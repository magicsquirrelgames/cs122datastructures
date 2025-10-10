#include "FitnessAppWrapper.hpp"

FitnessAppWrapper::FitnessAppWrapper(){}
FitnessAppWrapper::FitnessAppWrapper(const FitnessAppWrapper &copy){}
FitnessAppWrapper::~FitnessAppWrapper(){}
FitnessAppWrapper &FitnessAppWrapper::operator= (const FitnessAppWrapper &rhs){}

void FitnessAppWrapper::runApp()
{

}

void FitnessAppWrapper::displayMenu()
{
    system("cls");
    cout << "===============================================\n";
    cout << "Welcome to the Super Duper Fitness Manager 6000\n";
    cout << "===============================================\n";
    cout << "1. Load weekly plan from file\n";
    cout << "2. Load exercise plan from file\n";
    cout << "3. Store weekly diet plan to file\n";
    cout << "4. Store weekly exercise plan to file\n";
    cout << "5. Display weekly diet plan\n";
    cout << "6. Display weekly exercise plan\n";
    cout << "7. Edit daily diet plan\n";
    cout << "8. Edit daily exercise plan\n";
    cout << "9. Exit\n";
    cout << "Please select an option: ";

    int selection = 0;
    cin >> selection;

    switch(selection)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
    }
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{

}

void FitnessAppWrapper::displayDailyPlan()
{

}

void FitnessAppWrapper::displayWeeklyPlan()
{

}

void FitnessAppWrapper::storeDailyPlan()
{

}

void FitnessAppWrapper::storeWeeklyPlan()
{

}