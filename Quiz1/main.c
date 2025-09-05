#include <stdio.h>

char *myStrncpy (char *destination, const char *source, int n);
char *strCpyRec(char* source, char*destination);
void bubble_sort(int* numbers, int count);

int main()
{
    char string1[10] = "cat";
    char string2[10] = "";

    strCpyRec(string1, string2);

    puts(string2);

    int list[10] = {4,7,11,32,9,3,21,17,29,5};
    bubble_sort(list,10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d, ", list[i]);
    }
}

char *myStrncpy(char *destination, const char *source, int n)
{
    // determine the length of the source
    int sourceLength = 0;
    while(source[sourceLength] != '\0')
    {
        sourceLength++;
    }

    // copy source to destination
    for(int i = 0; i < n; i++)
    {
        if(i < sourceLength)
        {
            destination[i] = source[i];
        }
        else
        {
            destination[i] = '\0';
        }
    }

    // return destination
    return destination;
}

char *strCpyRec(char* source, char*destination)
{
    if(source[0] == '\0') // base case
    {
        destination[0] = '\0';
        return destination;
    }
    else // recursive case
    {
        destination[0] = source[0];
        return strCpyRec(source + 1, destination + 1);
    }
}

void bubble_sort(int* numbers, int length)
{
    if(length > 1) // only sort if there is more than 1 element
    {
        int sorted = length;
        int didSomething = 1;
        while(didSomething == 1) // swap elements until the array is sorted
        {
            didSomething = 0;
            for(int i = 0; i < sorted; i++)
            {
                if(numbers[i] > numbers[i+1])
                {
                    int temp = numbers[i];
                    numbers[i] = numbers[i+1];
                    numbers[i+1] = temp;
                    didSomething = 1;
                }
            }
            sorted -= 1;
        }
    }
}