#include "FitnessAppWrapper.hpp"

FitnessAppWrapper::FitnessAppWrapper()
{

}

FitnessAppWrapper::FitnessAppWrapper(const FitnessAppWrapper &copy)
{
    this->dietPlan = copy.dietPlan;
    this->exercisePlan = copy.exercisePlan;
}

FitnessAppWrapper::~FitnessAppWrapper()
{

}

FitnessAppWrapper &FitnessAppWrapper::operator= (const FitnessAppWrapper &rhs)
{
    this->dietPlan = rhs.dietPlan;
    this->exercisePlan = rhs.exercisePlan;

    return *this;
}

void FitnessAppWrapper::runApp()
{
    loadWeeklyPlan(dietPlan);
    loadWeeklyPlan(exercisePlan);
    displayMenu();
}

void FitnessAppWrapper::displayMenu(bool exit)
{
    if(exit)
    {
        return;
    }
    system("cls");
    cout << "===============================================\n";
    cout << "Welcome to the Super Duper Fitness Manager 6000\n";
    cout << "===============================================\n";
    cout << "1. Load weekly diet plan from file\n";
    cout << "2. Load weekly exercise plan from file\n";
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
            loadWeeklyPlan(dietPlan);
            cout << "Weekly diet plan loaded." << endl;
            break;
        case 2:
            loadWeeklyPlan(exercisePlan);
            cout << "Weekly exercise plan loaded." << endl;
            break;
        case 3:
            storeWeeklyPlan(dietPlan);
            cout << "Weekly diet plan stored." << endl;
            break;
        case 4:
            storeWeeklyPlan(exercisePlan);
            cout << "Weekly exercise plan stored." << endl;
            break;
        case 5:
            displayWeeklyPlan(dietPlan);
            break;
        case 6:
            displayWeeklyPlan(exercisePlan);
            break;
        case 7:
            editDailyPlan(dietPlan);
            break;
        case 8:
            editDailyPlan(exercisePlan);
            break;
        case 9:
            cout << "The program will now exit when you return to the menu." << endl;
            exit = true;
            storeWeeklyPlan(dietPlan);
            storeWeeklyPlan(exercisePlan);
            break;
    }

    string response;
    cout << "Press enter to return to the menu." << endl;
    getline(cin, response);
    getline(cin, response);
    displayMenu(exit);
}

void FitnessAppWrapper::loadDailyPlan(ifstream &inFile, vector<DietPlan> &plan)
{
    DietPlan newDietPlan;

    string newName;
    int newGoal;
    string newDate;

    inFile >> newName;
    inFile >> newGoal;
    inFile >> newDate;

    newDietPlan.setName(newName);
    newDietPlan.setGoal(newGoal);
    newDietPlan.setDate(newDate);

    plan.push_back(newDietPlan);
}

void FitnessAppWrapper::loadDailyPlan(ifstream &inFile, vector<ExercisePlan> &plan)
{
    ExercisePlan newExercisePlan;

    string newName;
    int newGoal;
    string newDate;

    inFile >> newName;
    inFile >> newGoal;
    inFile >> newDate;

    newExercisePlan.setName(newName);
    newExercisePlan.setGoal(newGoal);
    newExercisePlan.setDate(newDate);

    plan.push_back(newExercisePlan);
}

void FitnessAppWrapper::loadWeeklyPlan(vector<DietPlan> &plan)
{
    plan.clear();
    ifstream inFile("dietPlans.txt");
    if(!inFile)
    {
        cout << "Error opening dietPlans.txt" << endl;
        return;
    }
    for(int i = 0; i < 7; i++)
    {
        loadDailyPlan(inFile, plan);
    }
}

void FitnessAppWrapper::loadWeeklyPlan(vector<ExercisePlan> &plan)
{
    plan.clear();
    ifstream inFile("exercisePlans.txt");
    if(!inFile)
    {
        cout << "Error opening exercisePlans.txt" << endl;
        return;
    }
    for(int i = 0; i < 7; i++)
    {
        loadDailyPlan(inFile, plan);
    }    
}

void FitnessAppWrapper::displayDailyPlan(vector<DietPlan> &plan, int index)
{
    cout << plan[index];
}

void FitnessAppWrapper::displayDailyPlan(vector<ExercisePlan> &plan, int index)
{
    cout << plan[index];
}

void FitnessAppWrapper::displayWeeklyPlan(vector<DietPlan> &plan)
{
    for(int i = 0; i < plan.size(); i++)
    {
        displayDailyPlan(plan, i);
        cout << endl;
    }
}

void FitnessAppWrapper::displayWeeklyPlan(vector<ExercisePlan> &plan)
{
    for(int i = 0; i < plan.size(); i++)
    {
        displayDailyPlan(plan, i);
        cout << endl;
    }
}

void FitnessAppWrapper::storeDailyPlan(ofstream &outFile, vector<DietPlan> &plan, int index)
{
    outFile << plan[index] << endl;
}

void FitnessAppWrapper::storeDailyPlan(ofstream &outFile, vector<ExercisePlan> &plan, int index)
{
    dietPlanFile << plan[index] << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(vector<DietPlan> &plan)
{
    ofstream outFile("dietPlans.txt", ios::out);
    if(!outFile)
    {
        cout << "Error opening dietPlans.txt." << endl;
        return;
    }
    for(int i = 0; i < plan.size(); i++)
    {
        storeDailyPlan(outFile, plan, i);
    }
    outFile.close();
}

void FitnessAppWrapper::storeWeeklyPlan(vector<ExercisePlan> &plan)
{
    ofstream outFile("exercisePlans.txt", ios::out);
    if(!outFile)
    {
        cout << "Error opening exercisePlans.txt." << endl;
        return;
    }
    for(int i = 0; i < plan.size(); i++)
    {
        storeDailyPlan(outFile, plan, i);
    }
    outFile.close();
}

void FitnessAppWrapper::editDailyPlan(vector<DietPlan> &plan)
{
    cout << "Please enter the date of the daily plan you woud like to edit. (mm/dd/yyyy): ";

    string response;
    cin >> response;

    bool foundPlan = false;
    for(int i = 0; i < plan.size(); i++)
    {
        if(plan[i].getDate() == response && !foundPlan)
        {
            foundPlan = true;

            string newName;
            int newGoal;
            string newDate;

            cout << "What you would like to change the name to?: ";
            cin >> newName;

            cout << "What you would like to change the goal calories to?: ";
            cin >> newGoal;

            cout << "What you would like to change the date to? (mm/dd/yyyy): ";
            cin >> newDate;

            plan[i].setName(newName);
            plan[i].setGoal(newGoal);
            plan[i].setDate(newDate);

            cout << "Daily plan updated." << endl;
        }
    }

    if(!foundPlan)
    {
        cout << "Could not find a plan matching that date." << endl;
    }
}

void FitnessAppWrapper::editDailyPlan(vector<ExercisePlan> &plan)
{
    cout << "Please enter the date of the daily plan you woud like to edit. (mm/dd/yyyy): ";

    string response;
    cin >> response;

    bool foundPlan = false;
    for(int i = 0; i < plan.size(); i++)
    {
        if(plan[i].getDate() == response && !foundPlan)
        {
            foundPlan = true;

            string newName;
            int newGoal;
            string newDate;

            cout << "What you would like to change the name to?: ";
            cin >> newName;

            cout << "What you would like to change the goal steps to?: ";
            cin >> newGoal;

            cout << "What you would like to change the date to? (mm/dd/yyyy): ";
            cin >> newDate;

            plan[i].setName(newName);
            plan[i].setGoal(newGoal);
            plan[i].setDate(newDate);

            cout << "Daily plan updated." << endl;
        }
    }

    if(!foundPlan)
    {
        cout << "Could not find a plan matching that date." << endl;
    }
}