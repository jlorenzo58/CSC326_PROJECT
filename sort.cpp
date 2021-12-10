#include "sort.h"
#include<stack>

//go through all pairs to determine which is larger.
void sorts::bubble(int* arr, int length, int& steps) const {
    int temp;

    // Increment steps for int i = 0;
    steps++;
    // Make n amount of passes.
    for (int i = 0; i < length; i++) {

        // Increment steps for i < length comparison and i++
        steps += 2;

        // Increment steps for int j = 0;
        steps++;
        // Loop through the current sequence minus the amount of passes made.
        for (int j = 0; j < length - i - 1; j++) {

            // Increment steps for j < length-i-1 comparison and j++
            steps += 2;

            // Increment steps for if comparisons.
            steps += 1;
            if (*(arr + j) > * (arr + j + 1)) {
                steps++;
                temp = *(arr + j);
                // Assign the current element the value of the next element.
                steps++;
                *(arr + j) = *(arr + j + 1);
                // Assign the next element's value the value of the cached value.
                steps++;
                *(arr + j + 1) = temp;
                // Increment steps for swap.
                steps += 1;
            }
        }
        //increment for the last condition check
        steps++;
    }
    //increment for the last for loop condition check.
}

void sorts::selection(int* arr, int length, int& steps) const {
    int highest, temp;

    // Increment steps for int i = 0 and first condition check.
    steps++;
    for (int i = 0; i < length; i++, steps++) {
        //for the condition statement.
        steps++;

        steps++;
        highest = 0;

        // Increment steps for int j = 0
        steps++;
        for (int j = 0; j < length - i; j++, steps++) {

            // Increment steps for j<length
            steps++;

            // Increment steps for if comparision.
            steps += 1;
            if (*(arr + j) > * (arr + highest)) {
                steps++;
                highest = j;
            }
        }
        //increment steps for the last for loop condition check.
        steps++;

        // Temporarily store the highest value.
        temp = *(arr + highest);
        steps++;
        // Swap.
        *(arr + highest) = *(arr + length - 1 - i);
        *(arr + length - 1 - i) = temp;
        // Increment steps for the swap. +1
        steps += 2;
    }
    //increment steps for the last for loop condition check.
    steps++;
}

void sorts::insertion(int* arr, int length, int& steps) const {

    int j, temp;

    // Increment steps for int i = 0
    steps ++;

    // Loop through the array until length is reached.
    for (int i = 0; i < length; i++) {

        // Increment steps for i<length & i++
        steps +=2;

        // Increment steps for j = i;
        steps ++;
        // Set the current to be checked element.
        j = i;

        // Swap the element backwards until it is greater than the element before it.
        // Increment steps for condition checks
        while (j > 0 && *(arr + j) < *(arr + j - 1)) {
            steps += 2;
            temp = *(arr + j);
            *(arr + j) = *(arr + j - 1);
            *(arr + j - 1) = temp;
            j -= 1;
            // Increment steps for the swap
            steps += 4;

            // Increment steps for the next while loop conditions. +2
            steps += 2;
        }
    }
    return;
}

//Divide and Conquer(recursive solution)
void sorts::merge(int* arr, int length, int& steps) {
    // Increment steps for if comparison.
    steps += 1;
    if (length == 1) return;

    steps++;
    int size1 = length / 2, size2 = length - size1;

    merge(arr, size1, steps);
    merge(arr + size1, size2, steps);
    mergeStep(arr, size1, size2, steps);
    return;
}

void sorts::mergeStep(int* arr, int n1, int n2, int& steps) {
    steps+=3;
    int* temp = new int[n1 + n2];
    int p1 = 0, p2 = 0;

    //Increment steps for first while comparison.
    steps += 1;
    while (p1 + p2 < n1 + n2) {

        //Increment steps for if comparions.
        steps += 1;
        if (p1 < n1 && arr[p1] <= arr[n1 + p2] || p1 < n1 && p2 >= n2) {
            steps += 1;
            temp[p1 + p2] = arr[p1++];
        }

        //Increment steps for if comparions.
        steps += 1;
        if (p2 < n2 && arr[n1 + p2] < arr[p1] || p2 < n2 && p1 >= n1) {
            steps += 1;
            temp[p1 + p2] = arr[n1 + p2++];
        }

        //Increment steps for next while comparison.
        steps += 1;
    }

    steps++;
    for (int i = 0; i < n1 + n2; i++) {
        steps += 2;

        steps++;
        arr[i] = temp[i];
    }
    steps++;

    steps += 2;
    delete[] temp;
    temp = NULL;
    return;
}

//1) Divide 2) conquer 3) combine
//tried doing recursively but kept getting stack overflow, so i used stack from stack library.
void sorts::quick(int* arr, int start, int length, int& steps) {
    int part;

    // arr and steps is shared, so these will not be pushed to stack
    steps++;
    std::stack<std::pair<int, int>> stck;
    
    steps += 1;
    stck.push({ start, length });

    // this while loop simulates recursion
    steps++;
    while (!stck.empty())
    {
        auto top = stck.top();
        steps++;
        stck.pop();

        // Get new values of start and length
        steps += 2;
        start = top.first;
        length = top.second;

        steps++;
        if (start < length) {
            //assignment and function call
            steps+=1;
            part = partitionStep(arr, start, length, steps);
            // quick(arr, start, part - 1, steps);
            steps++;
            stck.push({ start, part - 1 });

            // quick(arr, part + 1, length, steps);
            steps++;
            stck.push({ part + 1, length });
        }
        //for the next while loop condition check.
        steps++;
    }
}

int sorts::partitionStep(int* arr, int start, int length, int& steps) {
    steps += 2;
    int i = start - 1, j = start;
    steps++;
    int key = arr[length];   //pivot

    steps++;
    while (j < length) {
        // Increment steps for if comparison.
        steps += 1;
        if (arr[j] <= key) {
            steps++;
            i++;

            // Increment steps for if comparison.
            steps += 1;
            if (i != j) {

                swapThese(&arr[i], &arr[j], steps);
                // Increment steps for swap.
                steps += 1;

            }
        }
        steps++;
        j++;

        // Increment steps for next while comparison.
        steps += 1;
    }

    swapThese(&arr[i + 1], &arr[length], steps);
    // Increment steps for swap.
    steps += 1;

    steps++;
    return i + 1;
}

void sorts::swapThese(int* val1, int* val2, int & steps) {
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    steps += 3;
}