#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

using std::string;
using std::fstream;
using std::vector;

class FitnessAppWrapper
{
    public:
        FitnessAppWrapper();
        FitnessAppWrapper(const FitnessAppWrapper &copy);
        ~FitnessAppWrapper();
        FitnessAppWrapper &operator= (const FitnessAppWrapper &rhs);

       void runApp();
       void displayMenu();

    private:
        vector<DietPlan> dietPlan;
        vector<ExercisePlan> exercisePlan;

        void loadDailyPlan(fstream &fileStream, DietPlan &plan);
        void displayDailyPlan();
        void displayWeeklyPlan();
        void storeDailyPlan();
        void storeWeeklyPlan();
};