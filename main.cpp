//#include<iostream>
#include<iomanip>
#include<time.h>
#include"sort.h"
#include"instances.h"
using namespace std; 



//instances : Sorted, reverse, random permutation. Pass 0 for sorted, pass 1 for reverse, pass 2 for random.
//repeat is for the number of randomly generated instances
//if average is true, the prog will print out the average running time.
void prog(instances& instance, int repeat, int order, bool average);

//table to print out the time elapsed. for the 5 sorting algorithms
void printTimeTable(double table[][5],int repeat);

//table to print out the amount of steps for the 5 sorting algorithms
void printStepTable(int table[][5], int repeat);

//the array of n's
int getTheN(int column) {
    int arrN[8] = { 1,1,1,1,1,1,1,1 };
    switch (column) {
    case 0:
        return arrN[0];
        break;
    case 1:
        return arrN[1];
        break;
    case 2:
        return arrN[2];
        break;
    case 3:
        return arrN[3];
        break;
    case 4:
        return arrN[4];
        break;
    case 5:
        return arrN[5];
        break;
    case 6:
        return arrN[6];
        break;
    case 7:
        return arrN[7];
        break;
    default:
        break;
    }
    return 0;
}

int main() {
    //only one needed for all instances.
    instances instance;

    // sorted instance of n
    cout << "Sorted" << endl;
    prog(instance, 1, 0, false);
    
    // reversed Instance of n
    cout << "Reversed. " << endl;
    prog(instance, 1, 1, false);

    // random permutation of n
    cout << "Random permutation. " << endl;
    prog(instance, 1, 2, false);

    //random permutation for 50 sets of the n's
    cout << "Averages for 50 sets. " << endl;
    prog(instance, 50, 2, true);

	system("pause");
	return 0;
}

void printTimeTable(double table[][5], int repeat) {
    cout << left << setw(12) << "n"<< "\t";
    for (int i = 0; i < 5; i++) {
        switch (i) {
        case 0:
            cout << left << setw(12) << "insertion"<<"\t";
            break;
        case 1:
            cout << left << setw(12) << "selection"<<"\t";
            break;
        case 2:
            cout << left << setw(12) << "bubble"<<"\t";
            break;
        case 3:
            cout << left << setw(12) << "merge"<<"\t";
            break;
        case 4:
            cout << left << setw(12) << "quick"<<"\t";
            break;
        }
    }
    cout << endl;

    //Loop through each row.
    for (int i = 0; i < 8; i++) {
        // Get rows data.
        int n = getTheN(i);

        // Print data
        cout << left << setw(12) << n << "\t";

        // Loop through each column.
        for (int j = 0; j < 5; j++) {
            //this will also print out the average, if reapeat equals 1, element in table[i][j] remains the same. If repeat = 50, the element will be divided by 50.
            cout << left << setw(12) << fixed << table[i][j] / repeat << "\t";
        }
        cout << endl;
    }

    cout << endl << endl;
}

void printStepTable(int table[][5], int repeat) {

        cout << left << setw(12) << "n"<<"\t";
        for (int i = 0; i < 5; i++) {
            switch (i) {
            case 0:
                cout << left << setw(12) << "insertion"<<"\t";
                break;
            case 1:
                cout << left << setw(12) << "selection"<<"\t";
                break;
            case 2:
                cout << left << setw(12) << "bubble"<<"\t";
                break;
            case 3:
                cout << left << setw(12) << "merge"<<"\t";
                break;
            case 4:
                cout << left << setw(12) << "quick"<<"\t";
                break;
            }
        }
        cout << endl;

        //Loop through each row.
        for (int i = 0; i < 8; i++) {
            // Get rows data.
            int n = getTheN(i);

            // Print row info.
            cout << left << setw(12) << n << "\t";

            // Loop through each column.
            for (int j = 0; j < 5; j++) {
                cout << left << setw(12) << fixed << table[i][j] / repeat << "\t";     //average
            }
            cout << endl;
        }

        cout << endl << endl;
}

void prog(instances& instance, int repeat, int order, bool average) {

    sorts sort;

    // Data to store the start time.
    clock_t beginTime;
    //float time;
    //data to store the number of steps
    int steps;
    double TotalTime;  //for time elapsed.

    // Arrays to hold values for printing. 8 n's by 5 sorts.
    int stepsTable[8][5];  //steps are always whole numbers
    double timeTable[8][5];  //time can be decimal

    // Loop through each row.
    for (int i = 0; i < 8; i++) {

        // Determine the nth element. will sart with 100, 300, ... , 50000
        int n = getTheN(i);
        instance.initiate(n);  //initiate the array

        // Loop through each column
        for (int j = 0; j < 5; j++) {

            // Initialize data
            steps = 0;
            TotalTime = 0;

            //the order determines which instance will be working on, increasing, reversed, random permutation. The repeat determines how many sets will be created.
            for (int r = 0; r < repeat; r++) {

                // Pre-order sequence.
                switch (order) {
                case 0:
                    instance.increasing();
                    break;
                case 1:
                    instance.decreasing();
                    break;
                case 2:
                    instance.random();
                    break;
                default:
                    instance.random();
                    break;
                }

                // Get start time.
                beginTime = clock();

                // Run a test based on column. If j=0, were working w insertion. j=1, working w selection and so on. the time will still be running during the sorting.
                switch (j) {
                case 0:
                    sort.insertion(instance.getArray(), instance.getLength(), steps);
                    break;
                case 1:
                    sort.selection(instance.getArray(), instance.getLength(), steps);
                    break;
                case 2:
                    sort.bubble(instance.getArray(), instance.getLength(), steps);
                    break;
                case 3:
                    sort.merge(instance.getArray(), instance.getLength(), steps);
                    break;
                case 4:
                    sort.quick(instance.getArray(), 0, instance.getLength() - 1, steps);
                    break;
                default:
                    break;
                }

                // algorithm for getting time elapsed
                TotalTime = (double)(clock() - beginTime) / CLOCKS_PER_SEC;

                // Calculate time elapsed.
                //timeElapsed = startTime - endTime;
                //time+= (float)timeElapsed/CLOCKS_PER_SEC;
                //time += (float)time3 / CLOCKS_PER_SEC;
            }

            // Assign value to table.
            stepsTable[i][j] = steps;
            timeTable[i][j] = TotalTime;
        }
    }

    //calling the function will print out the steps table
    cout << "The steps amount in terms of assignment, swaps, and condition checks." << endl;
    printStepTable(stepsTable, 1);

    //calling this function will print out the steps table
    cout << "Time in seconds. " << endl;
    printTimeTable(timeTable, 1);

    // if user wanted average to be checked, pass true in prog call.
    if (average) {
        cout << "Averages" << endl;

        // Print average step table 
        cout << "Average amount of steps" << endl;
        printStepTable(stepsTable, repeat);

        // Print average cpu running time table
        cout << "Average cpu running time" << endl;
        printTimeTable(timeTable, repeat);
    }

}
