#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

using std::string;
using std::fstream;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

class FitnessAppWrapper
{
    public:
        FitnessAppWrapper();
        FitnessAppWrapper(const FitnessAppWrapper &copy);
        ~FitnessAppWrapper();
        FitnessAppWrapper &operator= (const FitnessAppWrapper &rhs);

       void runApp();
       void displayMenu(bool exit = false);

    private:
        vector<DietPlan> dietPlan;
        vector<ExercisePlan> exercisePlan;

        fstream dietPlanFile;
        fstream exercisePlanFile;

        void loadDailyPlan(ifstream &inFile, vector<DietPlan> &plan);
        void loadDailyPlan(ifstream &inFile, vector<ExercisePlan> &plan);
        void loadWeeklyPlan(vector<DietPlan> &plan);
        void loadWeeklyPlan(vector<ExercisePlan> &plan);
        void displayDailyPlan(vector<DietPlan> &plan, int index);
        void displayDailyPlan(vector<ExercisePlan> &plan, int index);
        void displayWeeklyPlan(vector<DietPlan> &plan);
        void displayWeeklyPlan(vector<ExercisePlan> &plan);
        void storeDailyPlan(ofstream &outFile, vector<DietPlan> &plan, int index);
        void storeDailyPlan(ofstream &outFile, vector<ExercisePlan> &plan, int index);
        void storeWeeklyPlan(vector<DietPlan> &plan);
        void storeWeeklyPlan(vector<ExercisePlan> &plan);
        void editDailyPlan(vector<DietPlan> &plan);
        void editDailyPlan(vector<ExercisePlan> &plan);
};