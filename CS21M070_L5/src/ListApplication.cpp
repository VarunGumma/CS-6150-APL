/**************************************************************************
 *
 *  File: ListApplication.cpp
 *
 *  Purpose: Performs big integer (integers which cannot be stored in primitive datatypes) subtraction
 *
 *  Author: Varun Gumma 
 *
 *  Date: 20-09-2021
 *
 *  Bugs: NA
 *
 *  Change Log: <Date> <Author>
 *              <Changes>
 *
 **************************************************************************/

#include "../include/ElementType.h"
#include "../include/ListADT.h"
#include <iostream>
#include "string.h"
using namespace std;

/*********************************************************************************************************
 * BigIntSubstract -- Subtracts two very large integers which can't be stored in regular C++ formats
 * Input: Integers to be subtracted in the format as strings.
 * Output: Returns a list which is the result of the subtraction, i.e. param1 - param2
 * Bugs: NA
*********************************************************************************************************/

List  BigIntSubtract(char *string1, char *string2) 
{
    int len1 = strlen(string1); /*length of the first number, minuend*/
    int len2 = strlen(string2); /*length of the second number, substrhend*/
    int lenDiff = len1 - len2;  /*Difference in the lengths of the two strings*/

    List minuend = List();  /*Create the minuend list and set it to null*/
    minuend.makeNull();
    
    List subtrahend = List();   /*Create the substrahend list and set it to null*/
    subtrahend.makeNull();
    
    List result = List();   /*Create the result list and set it to null*/
    result.makeNull();
    
    for(int i = 0; i < len1; i++)   /*loop through the first integer given as a string*/
        minuend.insert(string1[i] - '0', minuend.end());    /*Convert it to a list by appending the digits to the empty list*/
    
    for(int i = 0; i < lenDiff; i++)    
        subtrahend.insert(0, subtrahend.end()); /*first add required number of 0s for ease of operation. Coz of this minuend and subtrahend have same size*/
    for(int i = 0; i < len2; i++)   /*loop through the second integer given as a string*/
        subtrahend.insert(string2[i] - '0', subtrahend.end());  /*Convert it to a list by appending the digits to the empty list*/
    
    
    bool prevBorrow = false;    /*keep a boolean variable to check if a borrow has been made previously*/
    Position minuendPos = minuend.end() - 1;    /*as we subtract R-L, store indices of the last element of the list*/
    Position subtrahendPos = subtrahend.end() - 1;
    while(minuendPos >= minuend.first())    /*loop over each element of the lists*/
    {
        elementType first = minuend.retrieve(minuendPos);   /*digit to be considered from minuend*/
        elementType second = subtrahend.retrieve(subtrahendPos);    /*digit to be considered from subtrahend*/
        if(prevBorrow)  /*If a previous borrow has been made, then the current first digit has to be reduced as it gave the borrow*/
            first--;
        if(first < second)  /*but now if the minuend digit is less than the subtrahend digit*/
        {
            prevBorrow = true;  /*make a borrow from the next digit of the minuend, i.e. keep prevBorrow flag*/
            first += 10;    /*and increment the minuend digit face-value by 10*/
        }
        else
            prevBorrow = false; /*If now borrow is required, turn off prevBorrow flag*/
        
        result.insert(first - second, result.first());  /*insert the difference of the digits at the beginning of the result list, as result forms R-L*/
        minuendPos--;  
        subtrahendPos--;    /*decrement pointers of both lists to access next elements*/
    }   
    
    while(not result.isEmpty() and not result.retrieve(result.first())) /*while the list is not empty and the first element of the list is not 0*/ 
        result.delItem(result.first()); /*delete it*/

    if(result.isEmpty())    /*if the list is empty*/
        result.insert(0, result.end()); /*just append a 0, to denote 0 value*/
    
    return result;  /*return the result list to the main function*/
}

/*********************************************************************************************************
 * main -- driver program for this code
 * Input: NA
 * Output: NA, just calls BigIntSubstract function which returns the difference in the form of a list
 * Bugs: NA
*********************************************************************************************************/

int main()
{ 
    int testCases;
    char string1[101], string2[101];
    List result;
    cin>>testCases;

    while(testCases--)
    {
        cin >> string1;
        cin >> string2;
    
        result = (List)BigIntSubtract(string1, string2);
        cout << string1 << " - " << string2 << " = ";
        result.printList();
    }
    return 0;
}