#include "stdlib.h"
#include "../include/SortingAlgos.h"

/*-------------------------------------------------------------------------
 *  Swap --
 *    Args: pointers to the two numbers to be swapped
 *    Returns: NA, just swaps the two numbers passed by reference
 *    Throws: NA
 *    See: NA
 *    Bugs: NA
 -------------------------------------------------------------------------*/
void Swap(int *a, int *b) 
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}   /*  End of Swap     End of Swap   */


/*-------------------------------------------------------------------------
 *  InsertionSort --
 *    Args: array to be sorted, starting index of array, ending index of array
 *    Returns: NA, just sorts the passed array
 *    Bugs: NA
 * -------------------------------------------------------------------------*/

void InsertionSortAsc(int *array, int start, int end)
{
    int i, j, first, p, x;

    first = array[0]; //Temporary storage for the first element of the array

    p = 0; //Location of the minimum element in the array

    //Loop to identify the minimum element in the array with loop variable i
    for (i = 0; i <= end; i++) 
    {
        if(array[i] <= first)
        {
            first = array[i];
            p = i;
        }
    }

    //Swap the minimum element with first element of the array
    Swap(array + p, array);

    //Loop for rearranging the elements of the array
    for (i = 2; i <= end; i++) 
    {
        x = array[i];
        for(j = i-1; j >= 0 && x <= array[j]; j--)
            array[j+1] = array[j];
        array[j+1] = x;
    }

}   /*  End of InsertionSort        End of InsertionSort   */

/*-------------------------------------------------------------------------
 *  Merge --
 *    Args: array to sorted, temporary array, left index of 1st array, left index of 2nd array, right index of 2nd array
 *    Returns: NA, just merges 1st and 2nd sorted subarrays according to given pointers
 *    Bugs: NA
 * -------------------------------------------------------------------------*/

void Merge(int *a, int *b, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int tmpPosCopy = leftPos;
    int numElements = (leftEnd - leftPos + 1) + (rightEnd - rightPos + 1);
    int i;

    //Compare the two sub arrays and merge to temporary array b
    while (leftPos <= leftEnd && rightPos <= rightEnd) 
    {
        if(a[leftPos] <= a[rightPos])
            b[tmpPos++] = a[leftPos++];
        else
            b[tmpPos++] = a[rightPos++];
    }
    // Copy the remaining elements of one of the sub array
    while (leftPos <= leftEnd)
        b[tmpPos++] = a[leftPos++];
    // Copy the remaining elements of the other sub array
    while (rightPos <= rightEnd)
        b[tmpPos++] = a[rightPos++];

    i = 0;
    // Merge the temp arrays back into the original array a
    while (i < numElements) 
    {
        a[tmpPosCopy + i] = b[tmpPosCopy + i];
        i++;
    }

}   /*  End of Merge        End of Merge   */

/*-------------------------------------------------------------------------
 *  MergeSort --
 *    Args: array to be sorted, temporary array, left index to begin sorting, right index to end sorting
 *    Returns: NA, helps sort left and right subarrays and merges them
 *    Bugs: NA
 * -------------------------------------------------------------------------*/

void MergeSort(int *a, int *b, int left, int right)
{
    int middle;
    if (left < right) 
    {
        middle = (left + right - 1) / 2;
        MergeSort (a, b, left, middle);
        MergeSort (a, b, middle+1, right);
        Merge (a, b, left, middle+1, right);
    }

}   /*  End of MergeSort        End of MergeSort   */


/*-------------------------------------------------------------------------
 *  MergeSortAsc --
 *    Args: array to be sorted, left index to start sorting, right index to end sorting
 *    Returns: NA, sorts the passed array
 *    Bugs: NA
 * -------------------------------------------------------------------------*/

void MergeSortAscend(int *array, int left, int right)
{
    int *tmp;
    //Create a temporary array with the same size of input array
    tmp = (int*)malloc((right - left + 1) * sizeof(int));
    //Function call to MergeSort function
    MergeSort (array, tmp, left, right);
    free(tmp);
}   /*  End of MergeSortAsc     End of MergeSortAsc   */

/*-------------------------------------------------------------------------
 *  SortAlgo:
 *    Args: type of algo to be used (0 for insertion, 1 for merge), array to be sorted, starting index of array, ending index, function pointer
 *    Returns: NA, just runs expected sorting algorithm
 *    Bugs: NA
 * -------------------------------------------------------------------------*/

void SortAlgo (int type, int* array, int start, int end, void (*Sort)()) 
{
    if(!type)
        Sort = &InsertionSortAsc;
    else
        Sort = &MergeSortAscend;
    Sort(array, start, end);
}