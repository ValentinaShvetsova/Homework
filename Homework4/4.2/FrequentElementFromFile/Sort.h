#pragma once

// This function is recieve array and its endings
void quickSort(int a[], int leftCounter, int rightCounter);

// This function break array on smaller parts
int findBorderIndex(int array[], int borderElement, const int leftBorder, const int rightBorder);

// This function sort arrays which are less then 10 elements
void insertionSort(const int leftCounter, const int rightCounter, int array[]);