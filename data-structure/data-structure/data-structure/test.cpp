//
//  test.cpp
//  data-structure
//
//  Created by Edward dawson on 19/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void insertionSort(int *array, int length)
{
    int temp;
    for(int i = 1; i < length; i++){
        int j = i;
        while(array[j] < array[j-1] && j > 0){
            temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }
}

void selectionSort(int *array, int length)
{
    int currentMin, currentPos, temp;
    for(int i = 0; i < length - 1; i++){
        currentMin = array[i]; currentPos = i;
        for(int j = i; j < length; j++)
        {
            if(array[j] < currentMin)
            {
                currentPos = j;
                currentMin = array[j];
            }
        }
        temp = array[i];
        array[i] = array[currentPos];
        array[currentPos] = temp;
    }
}

void heapSort(int * array, int length)
{

}


void bubbleSort(int * array, int length)
{
    int temp;
    for(int i = 0; i < length-1;i++)
        for(int j = 0; j < length-1;i++){
            if(array[j] > array[j + 1]){
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
}

void mergeSort(int* array, int length)
{
    
}

void shellSort(int *array, int length)
{
    
}


int partition(int* array, int low, int high)
{
    int pivot = array[high];
    int left = low - 1, right = low;
    for(; right < high; right++){
        if(array[right] < pivot){
            left++;
            int temp = array[right];
            array[right] = array[left];
            array[left] = temp;
        }
    }
    array[high] = array[left + 1];
    array[left + 1] = pivot;
    return left + 1;
}

void quickSort(int* array, int low, int high)
{
    if(high > low){
        int index = partition(array, low, high);
        quickSort(array, low, index - 1);
        quickSort(array, index + 1, high);
    }
}


void bucketSort(int* array, int length)
{
    
}

int main()
{
    int array1[]= {1,8,2,1,4,5,6,3,2,34,5};
    int array2[]= {1,8,2,1,4,5,6,3,2,34,5};
    insertionSort(array1, 11);
    selectionSort(array2, 11);
    for(int i = 0; i < 11; i++)
        cout << array1[i] << ' ';
    cout << endl;
    for(int i = 0; i < 11; i++)
        cout << array2[i] << ' ';
    cout << endl;
}
