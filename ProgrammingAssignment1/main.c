#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;

FitbitData *parseFile(FILE *inputStream, FitbitData *output);
char* batheLineInCleansingFire(char* line);

int main()
{
    FitbitData fitbitData[1440];

    FILE * inputStream = fopen("FitbitData.csv", "r");
    if (inputStream != NULL)
    {
        parseFile(inputStream, fitbitData);
    }
    else
    {
        puts("ERROR: Could not open file.");
    }
    return 0;
}

FitbitData *parseFile(FILE *inputStream, FitbitData *output)
{
    char patientID[10] = "";
    char fitbitDataLine[100] = "";

    // get patient ID
    fgets(fitbitDataLine, 100, inputStream);
    strtok(fitbitDataLine, ",");
    strcpy(patientID, strtok(NULL, ","));

    // skip header line
    fgets(fitbitDataLine, 100, inputStream);

    // iterate through each line, cleaing the line and then parsing it
    while(fgets(fitbitDataLine, 100, inputStream) != NULL)
    {
        // clean the line
        batheLineInCleansingFire(fitbitDataLine);

        // read the line into a temporary file
        FitbitData temp;
        strcpy(temp.patient, strtok(fitbitDataLine, ","));
        strcpy(temp.minute, strtok(NULL, ","));
        temp.calories = atof(strtok(NULL, ","));
        temp.distance = atof(strtok(NULL, ","));
        temp.floors = atoi(strtok(NULL, ","));
        temp.heartRate = atoi(strtok(NULL, ","));
        temp.steps = atoi(strtok(NULL, ","));
        temp.sleepLevel = atoi(strtok(NULL, ","));

        // determine the target index for the line
        char minuteString[10];
        strcpy(minuteString, temp.minute);
        int hour = atoi(strtok(minuteString, ":"));
        int minute = atoi(strtok(NULL, ":"));
        int index = minute + (hour * 60);

        // save the fitbit data to the array
        if(temp.patient == patientID)
        {
            output[index] = temp;
        }
    }
    return output;
}

char *batheLineInCleansingFire(char * line)
{
    int index = 0;
    while (line[index + 1] != '\0')
    {
        // find missing entries
        if (line[index] == ',' && line[index + 1] == ',')
        {
            index++;

            // make space in the line for the invalid number
            int indexEnd = index;
            while (line[indexEnd] != '\0')
            {
                indexEnd++;
            }
            indexEnd += 5;
            for (int i = 0; i < 5; i++)
            {
                line[indexEnd] = line[indexEnd - 5];
                indexEnd--;
            }

            // put 99999 between double commas as an invald number
            for (int i = 0; i < 5; i++)
            {
                line[index] = '9';
                index++;
            }
        }
        index++;
    }
    return line;
}