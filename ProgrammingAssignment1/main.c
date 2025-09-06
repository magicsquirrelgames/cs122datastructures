/*
    Evan Yang
    9-5-2025
    Processes data taken from a fitbit over a 24 hour period.
*/

#include "programmingAssignment1.h";

int main()
{
    // open the file
    FitbitData fitbitData[1440];
    FILE * inputStream = fopen("FitbitData.csv", "r");

    // return if the file could not be opened
    if (inputStream == NULL)
    {
        puts("ERROR: Could not open input file.");
        return 0;
    }

    // parse the file
    parseFile(inputStream, fitbitData);

    // declare variables to hold the results
    double totalCalories = 0;
    double totalDistance = 0;
    unsigned int totalFloors = 0;
    unsigned int totalSteps = 0;
    double averageHeartrate = 0;
    unsigned int maxSteps = 0;
    unsigned int longestConsecutiveMinutesOfPoorSleep = 0;

    int heartRateCount = 0;
    int poorSleepCount = 0;

    // calculate the results
    for (int i = 0; i < 1440; i++)
    {
        if (fitbitData[i].calories != 99999) totalCalories += fitbitData[i].calories;
        if (fitbitData[i].distance != 99999) totalDistance += fitbitData[i].distance;
        if (fitbitData[i].floors != 99999) totalFloors += fitbitData[i].floors;
        if (fitbitData[i].steps != 99999)
        {
            totalSteps += fitbitData[i].steps;
            if (fitbitData[i].steps > maxSteps)
            {
                maxSteps = fitbitData[i].steps;
            }
        }
        if (fitbitData[i].heartRate != 99999)
        {
            heartRateCount++;
            averageHeartrate += fitbitData[i].heartRate;
        }
        if (fitbitData[i].sleepLevel < 2)
        {
            if (poorSleepCount > longestConsecutiveMinutesOfPoorSleep)
            {
                longestConsecutiveMinutesOfPoorSleep = poorSleepCount;
            }
            poorSleepCount = 0;
        }
        else
        {
            poorSleepCount++;
        }
    }
    averageHeartrate = averageHeartrate / heartRateCount;

    // open a file to output the data to
    FILE* outputFile;
    outputFile = fopen("Results.csv","w");

    // return if the file could not be opened
    if (outputFile == NULL)
    {
        puts("ERROR: Could not open output file.");
        return 0;
    }

    // print data to the console and to a file
    puts("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep");
    fputs("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n", outputFile);

    printf("%lf,%lf,%d,%d,%lf,%d,%d", totalCalories, totalDistance, totalFloors, totalSteps, averageHeartrate, maxSteps, longestConsecutiveMinutesOfPoorSleep);
    fprintf(outputFile, "%lf,%lf,%d,%d,%lf,%d,%d\n", totalCalories, totalDistance, totalFloors, totalSteps, averageHeartrate, maxSteps, longestConsecutiveMinutesOfPoorSleep);

    for (int i = 0; i < 1440; i++)
    {
        fprintf(outputFile,strcat(fitbitData[i].patient,","));
        fprintf(outputFile, strcat(fitbitData[i].minute, ","));
        fprintf(outputFile, "%lf,", fitbitData[i].calories);
        fprintf(outputFile, "%lf,", fitbitData[i].distance);
        fprintf(outputFile, "%d,", fitbitData[i].floors);
        fprintf(outputFile, "%d,", fitbitData[i].heartRate);
        fprintf(outputFile, "%d,", fitbitData[i].steps);
        fprintf(outputFile, "%d", fitbitData[i].sleepLevel);
        fprintf(outputFile, "\n");
    }

    fclose(inputStream);
    fclose(outputFile);

    return 0;
}