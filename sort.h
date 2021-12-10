#pragma once
#include<iostream>
#include<iomanip>
#include<time.h>

//object to hold all the sorting algorithms.
class sorts
{
public:
    sorts() {} //constr
    ~sorts() {} 
    void bubble(int* arr, int length, int& steps) const;
    void insertion(int* arr, int length, int& steps) const;
    void selection(int* arr, int length, int& steps) const;
    void merge(int* arr, int length, int& steps);
    void mergeStep(int* arr, int n1, int n2, int& steps);
    void quick(int* arr, int first, int last, int& steps);
    int partitionStep(int* arr, int start, int length, int& steps);
    void swapThese(int* val1, int* val2, int & steps);
private:
    //recursive solution to quicksort that doesnt work when n>4000. 
    /*long partition(int* arr, long l, long r, int& steps){
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (arr[i] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[r]);
        return i + 1;
    }
    void quickSort(int* arr, long left, long right, int& steps) {
        if (left < right) {
            long pivot = partition(arr, left, right, steps);
            quickSort(arr, left, pivot - 1, steps);
            quickSort(arr, pivot + 1, right, steps);

        }
    }
    */
};