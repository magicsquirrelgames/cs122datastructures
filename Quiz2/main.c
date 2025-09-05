#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentRecord
{
    char name[75];
	int ID;
	double GPA;
} StudentRecord;

int fileLineParser(FILE *inputFileStream, StudentRecord *arrStudentRecords);

int main()
{
	FILE * inputStream = fopen("studentRecords.csv", "r");
	StudentRecord studentRecords[3];
	fileLineParser(inputStream, studentRecords);
	for(int i = 0; i < 3; i++)
	{
		printf("%s, %d, %.2lf\n", studentRecords[i].name, studentRecords[i].ID, studentRecords[i].GPA);
	}
}

int fileLineParser(FILE *inputFileStream, StudentRecord *arrStudentRecords)
{
	char studentRecord[100] = "";
	int lineCount = 0;

    if(inputFileStream != NULL)
	{
		while(fgets(studentRecord, 100, inputFileStream) != NULL)
		{
            strcpy(arrStudentRecords[lineCount].name, strtok(studentRecord, ","));
            arrStudentRecords[lineCount].ID = atoi(strtok(NULL, ","));
			arrStudentRecords[lineCount].GPA = atof(strtok(NULL, "\n"));
            
            lineCount++; // increment line count
		}
	}
	return lineCount;
}
