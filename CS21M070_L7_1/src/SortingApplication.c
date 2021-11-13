/**************************************************************************
 *  $Id$
 *  File: CS21M070.c
 *
 *  Purpose: Sorts an array of integers using insertion and merge sort
 *
 *  Author: Varun Gumma 
 *
 *  Date: 27-09-2021
 *
 *  Bugs: NA
 *
 *  Change Log:	<Date> <Author>
 *  		    <Changes>
 *
 **************************************************************************/

#include "stdio.h"
#include "stdlib.h"
#include "../include/SortingAlgos.h"

int main() {

    int n;
    int *array;
    void (*Sort)();

    scanf ("%d", &n);
    //Create the array of size n
    array = (int*)malloc(n * sizeof(int));
    //Read the input array
    for(int i = 0; i < n; i++)
        scanf("%d", array + i);
    /*Write your code to make a function call to InsertionSort using function pointers with the help of SortAlgo function*/
    SortAlgo(0, array, 0, n-1, Sort);
    //Print the sorted(Ascending) array with each element is separated by space
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    free(array);


    scanf ("%d", &n);
    //Create the another array of size n
    array = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", array + i);
    /*Write your code to make a function call to MergeSortAscend using function pointers with the help of SortAlgo function*/
    SortAlgo(1, array, 0, n-1, Sort);
    //Print the sorted(Ascending) array with each element is separated by space
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    free(array);

    return 0;
}	/*  End of main		End of main   */


/**************************************************************************
 * $Log$
 *
 *                        End of FunctionPointersSortingO2Algos.c
 **************************************************************************/
