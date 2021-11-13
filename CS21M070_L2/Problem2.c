/***********************************************************
 * Program              : Problem2.c
 * 
 * Function             : reads intergers from a file appends the sum of those to the file.
 *                        here it is assumed that a new line is available to print the sum at the end.
 * 
 * Input                : one command line argument, for input file name
 * 
 * Output               : no output is printed, just the sum is appended to the input file words
 * 
 * Uses                 : a function to read integers linewise from the file
 *                        a function to append the sum to the file
 * 
 * Compilation          : Standard GCC compiler  
 * 
 **********************************************************/

#include <stdio.h>

/**********************************************************
 * ReadIntegersFromFile - Read the integers from the file, line-by-line
 * File name to be read is passed as parameter
 * 
 * Returns  : Sum of the numbers in the file
 * 
 * Method   : -
 *
 **********************************************************/

int ReadIntegersFromFile(char* fileName)
{
    int num, sum = 0;                                 /*Set a placeholder to store read integer and initialize sum to 0*/
    FILE* inputFilePointer = fopen(fileName, "r");    /*Open the input file in read mode*/

    while(1)                                          /*Keep an infinite loop to keep reading all the numbers*/
    {
        fscanf(inputFilePointer, "%d", &num);         /*Store current read integer from file in num variable*/
        if(feof(inputFilePointer))                    /*if an EOF is reached, terminate. All content is read*/
            break;
        sum += num;                                   /*Maintain the running sum*/
    }
    fclose(inputFilePointer);                         /*Makes sure to close the file*/
    return sum;                                       /*Return the sum of the numbers, End of Function*/
}

/**********************************************************
 * WriteSumToFile - Append the final sum to the input file
 * File name to be written to is passed as parameter
 * 
 * Returns  : NA, just modifies the file
 * 
 * Method   : -
 *
 **********************************************************/

void WriteSumToFile(int sum, char* fileName)
{
    FILE* outputFilePointer = fopen(fileName, "a");   /*Open the file in append mode*/
    fprintf(outputFilePointer, "%d\n", sum);          /*print the sum to the file*/
    fclose(outputFilePointer);                        /*Make sure to close the file*/      
    return;                                           /*End of Function*/  
}

/**********************************************************
 * main - driver for the program
 * has one cmd arguments, for input file
 * 
 * Returns  : 0 on successful termination
 * 
 * Method   : calls all required functions to complete the task
 *
 **********************************************************/

int main(int argc, char** argv)
{
    int sum = ReadIntegersFromFile(argv[1]);          /*Computer sum of those numbers*/
    WriteSumToFile(sum, argv[1]);                     /*Append result to inout file*/
    return 0;                                         /*End of Program*/
}