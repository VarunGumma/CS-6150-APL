/***********************************************************
 * Program              : Problem1.c
 * 
 * Function             : finds all unique words in a file (uncased) and prints them into another file
 * 
 * Input                : two command line arguments, one for input file name, other for output file name
 * 
 * Output               : no output is printed, just the output file is updated with necessary words
 * 
 * Uses                 : a function to set a complete string to '\0' values
 *                        a function to check if two strings are equal
 *                        a function to check if a given string is present in a set of strings
 *                        a function to read space-separated words from data in a file
 *                        a function write the unique set of words to another file
 * 
 * Compilation          : Standard GCC compiler  
 * 
 **********************************************************/

#include <stdio.h>
#define MAX_WORDS 1000
#define WORD_SIZE 50

char setOfWords[WORD_SIZE][MAX_WORDS];    /*Set of unique words*/
int wordPos = -1;                         /*Initial index to store the word. Always increment this value and store.*/

/**********************************************************
 * Reset - Resets the string to blank
 * String to be reset is passed as parameter.
 * Since arrays are passed by reference the string is set to '\0' throughout the file scope.
 * 
 * Returns  : NA
 * 
 * Method   : array is iterated elementwise and each character is set to '\0'
 *
 **********************************************************/

void Reset(char* s)
{
    /*Loop through the string*/
    for(int i = 0; i < WORD_SIZE; i++)
        s[i] = '\0';
    return;
}

/**********************************************************
 * CompareWords - Compares two words
 * Strings to be compared are passed as parameters and they are just compared to be equal.
 * 
 * Returns  : 1 if the strings are equal, else 0
 * 
 * Method   : arrays are iterated elementwise and character-wise compared
 *
 **********************************************************/

int CompareWords(char* s1, char* s2)
{
    /*Loop through the strings and check for differences*/
    for(int i = 0; i < WORD_SIZE; i++)
        if(s1[i] != s2[i])
            return 0;
    return 1;
}

/**********************************************************
 * IsPresent - Checks if a given string is present in the set of strings.
 * String passed as input is checked to be present in the set of strings.
 * Set of Strings is not passed as it is globally declared.
 * Internally uses CompareWords for string equality.
 * 
 * Returns  : 1 if the given string is present in the set, else 0
 * 
 * Method   : given string is compared to every other string elementwise
 *
 **********************************************************/

int IsPresent(char* word)
{
    for(int i = 0; i <= wordPos; i++)
        if(CompareWords(setOfWords[i], word)) /*Check is the given word is present in the set*/
            return 1;
    return 0;
}

/**********************************************************
 * ReadWordsFromFile - Reads the input file word by word and ignores punctuation
 * File name to be read is passed as input.
 * Internally uses IsPresent and Reset.
 * 
 * Returns  : NA, just populates the setOfWords array
 * 
 * Method   : -
 *
 **********************************************************/

void ReadWordsFromFile(char* fileName)
{
    char c;                 /*temporary character as a variable to hold content read from file*/
    char word[WORD_SIZE];   /*temporary array to store the current read string*/
    Reset(word);            /*Reset the created string, just-in-case*/
    int index = 0;          /*index indicates the position to append new characters to create the word*/
    
    
    FILE* inputFilePointer = fopen(fileName, "r");      /*Open the file in read mode*/
    while(c = fgetc(inputFilePointer))                  /*Read a new character from the file from current position*/
    {
        if(c == ' ' || c == EOF)                        /*If we encounter a space or EOF (End of File), it shows a new word has been read completely*/
        {
            if(!IsPresent(word))                        /*If the word is already present, dont append it to the set*/
            {
                wordPos++;                    
                for(int i = 0; i < WORD_SIZE; i++)
                    setOfWords[wordPos][i] = word[i];   /*Copy the word*/
            }
            Reset(word);                                /*Reset the word for future use, just-in-case*/
            index = 0;                                
            if(c == EOF)                                /*if the read character was EOF, we have completed the source file, break out*/
                break;
        }
        else if(c >= 'a' && c <= 'z' || c == '\'')      /*If a lowercase character/apostrophe is read, add it to the current word*/
            word[index++] = c;
        else if(c >= 'A' && c <= 'Z')                   /*If uppercase character is read, convert it to lowercase and add it*/
            word[index++] = c - 'A' + 'a';
    }
    fclose(inputFilePointer);                           /*Make sure to close the file*/
    return;                                             /*End of Function*/
}

/**********************************************************
 * WriteWordsToFile - prints all unique words to output file in space-separated manner
 * File name to be written to is passed as input.
 * 
 * Returns  : NA, just modifies output file
 * 
 * Method   : itertates through each word in the set of words and writes them to the file
 *
 **********************************************************/

void WriteWordsToFile(char* fileName)
{
    FILE* outputFilePointer = fopen(fileName, "w");             /*Open the output file in write mode*/
    for(int i = 0; i <= wordPos; i++)
        fprintf(outputFilePointer, "%s ", setOfWords[i]);       /*Write each word with space to output file*/
    fclose(outputFilePointer);                                  /*Make sure to close the file*/
    return;                                                     /*End of Function*/
}

/**********************************************************
 * main - driver for the program
 * has two cmd arguments, for input and output file respectively
 * 
 * Returns  : 0 on successful termination
 * 
 * Method   : calls all required functions to complete the task
 *
 **********************************************************/

int main(int argc, char** argv)
{
    ReadWordsFromFile(argv[1]); /*Read the words from the file and populate the setOfWords array*/
    WriteWordsToFile(argv[2]);  /*Write all the words from setOfWords array to the file*/
    return 0;                   /*End of Program*/
}