/*
    Evan Yang
    9-5-2025
    Processes data taken from a fitbit over a 24 hour period.
*/

#include "programmingAssignment1.h";

FitbitData* parseFile(FILE* inputStream, FitbitData* output)
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
    while (fgets(fitbitDataLine, 100, inputStream) != NULL)
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
        if (strcmp(temp.patient, patientID) == 0)
        {
            output[index] = temp;
        }
    }
    return output;
}

char* batheLineInCleansingFire(char* line)
{
    int index = 0;
    while (line[index] != '\0')
    {
        // find double commas
        if (line[index] == ',' && line[index + 1] == ',')
        {
            index++;

            // copy the rest of the string (including the second comma) to a temporary string
            char temp[100] = "";
            strcpy(temp, &line[index]);

            // replace the second comma with a null character and then concatenate
            line[index] = '\0';
            strcat(line, "99999");
            strcat(line, temp);

        } // find lines missing sleep level and set it 0
        else if (line[index] == ',' && line[index + 1] == '\n')
        {
            line[index + 1] = '0';
            line[index + 2] = '\n';
            line[index + 3] = '\0';
        }
        index++;
    }
    return line;
}