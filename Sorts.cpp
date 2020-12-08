//
//  Sorts.cpp
//  Sorting


#include "Sorts.hpp"
#include <time.h>
using namespace std;

bool compare(int array[], int array2[], int size)
{
    // compare the results      make this a function
    for(int i = 0; i < size; i++)
    {
        if(array[i] != array2[i])
        {
            cout << "Problem! Array elements not equal: [index]: a!=b [index: " << i << "]:" << array[i] << " != " << array2[i] << endl;
            return false;
        }
    }
    return true;
};

float bubbleSort(int array[], int size)
{
    clock_t start, total;
    start = clock();
    for (int i = 0; i < size; i++)
    {
        if (i%10000 == 0)
        {
            total = clock() - start;
            if (((float)total)/CLOCKS_PER_SEC > 600)
            {
                return 601;
            }
        }
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                std::swap(array[j], array[j+1]);
            }
        }
    }
    total = clock() - start;
    return ((float)total)/CLOCKS_PER_SEC;
};

float selectionSort(int array[], int size)
{
    int i, j, max_index;
    clock_t start, total;
    start = clock();
    for (i = size - (int)1; i >= 0 ; i --)
    {
        if (i%10000 == 0)
        {
            total = clock() - start;
            if (((float)total)/CLOCKS_PER_SEC > 600)
            {
                return 601;
            }
        }
        max_index = i;
        for (j = 0; j < i; j++)
        {
            if (array[j] > array[max_index])
            {
                max_index = j;
            }
        }
        std::swap(array[max_index], array[i]);
    }
    total = clock() - start;
    return ((float)total)/CLOCKS_PER_SEC;
};

float insertionSort(int array[], int size)
{
        clock_t start, total;
        int i, key, j;
        start = clock();
        for (i = 1; i < size; i++)
        {
            if (i%10000 == 0)
            {
                total = clock() - start;
                if (((float)total)/CLOCKS_PER_SEC > 600)
                {
                    return 601;
                }
            }
            key = array[i];
            j = i - 1;
            
            /* Move elements of arr[0..i-1], that are
             greater than key, to one position ahead
             of their current position */
            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = (int)key;
        }
        total = clock() - start;
    
        return ((float)total)/CLOCKS_PER_SEC;
};

float mergeSort(int array[], int size);
float quickSort(int array[], int size);


//Merge function from https://www.geeksforgeeks.org/merge-sort/
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    int * L;
    int * R;
    L = new int[n1];
    R = new int[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] R;
    delete[] L;
}

//Mergesort function from https://www.geeksforgeeks.org/merge-sort/
/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
float mergeSort(int arr[], int l, int r)
{
    clock_t start, total;
    start = clock();
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        total = mergeSort(arr, l, m);
        total = mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
    total = clock() - start;
    
    return ((float)total)/CLOCKS_PER_SEC;
}

//Partition function from https://www.geeksforgeeks.org/quick-sort/
//This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//Qucik sort  function from https://www.geeksforgeeks.org/quick-sort/
//The main function that implements QuickSort
//arr[] --> Array to be sorted
//low  --> Starting index
//high  --> Ending index
float quickSort(int arr[], int low, int high)
{
    clock_t start, total;
    start = clock();
    
    if (low < high)
    {
        //pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);
        
        // Separately sort elements before partition and after partition
        total = quickSort(arr, low, pi - 1);
        total = quickSort(arr, pi + 1, high);
    }
    total = clock() - start;
    
    return ((float)total)/CLOCKS_PER_SEC;
}

//heapify function from https://www.geeksforgeeks.org/heap-sort/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    // If largest is not root
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
//heap sort function from https://www.geeksforgeeks.org/heap-sort/
//heap sort
float heapSort(int arr[], int n)
{
    clock_t start, total;
    start = clock();
    //Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        
        if (i%10000 == 0)
        {
            total = clock() - start;
            if (((float)total)/CLOCKS_PER_SEC > 600)
            {
                return 601;
            }
        }
        heapify(arr, n, i);
    }
    
    //One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        //Move current root to end
        std::swap(arr[0], arr[i]);
        
        //call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    total = clock() - start;
    return ((float)total)/CLOCKS_PER_SEC;
}

//get max function from https://www.geeksforgeeks.org/radix-sort/
// Utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

//Countsort function from https://www.geeksforgeeks.org/radix-sort/
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int * output;
    output = new int[n]; // output array
    int i, count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    
    delete[] output;
}

//Radix Sort function from https://www.geeksforgeeks.org/radix-sort/
// The main function to that sorts arr[] of size n using Radix Sort
float radixSort(int arr[], int n)
{
    clock_t start, total;
    start = clock();
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
    
    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
    
    
    total = clock() - start;
    return ((float)total)/CLOCKS_PER_SEC;
}
