//
//  Sorts.hpp
//  Sorting
//


#ifndef Sorts_hpp
#define Sorts_hpp

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool compare(int array[], int array2[], int size);
float bubbleSort(int array[], int size);
float selectionSort(int array[], int size);
float insertionSort(int array[], int size);
float mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
float quickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high);
float heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
float radixSort(int arr[], int n);
void countSort(int arr[], int n, int exp);
int getMax(int arr[], int n);

#endif /* Sorts_hpp */
