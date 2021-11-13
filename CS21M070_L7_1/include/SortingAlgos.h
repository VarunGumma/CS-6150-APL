#ifndef SORTING_H
#define SORTING_H

void Swap(int *a, int *b);
void InsertionSortAsc(int *array, int start, int end);
void Merge(int *a, int *b, int leftPos, int rightPos, int rightEnd);
void MergeSort(int *a, int *b, int left, int right);
void MergeSortAscend(int *array, int left, int right);
void SortAlgo (int type, int* array, int start, int end, void (*Sort)());

#endif