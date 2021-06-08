/* 
 * File: histogram.cpp
 * --------------------------
 * A program that reads in an array of integers and then displays a histogram of
 * those numbers, divided into the ranges 0–9, 10–19, 20–29, and so forth, up to the
 * range containing only the value 100. 
 */

#include <iostream>
using namespace std;

/* Constant */

const int ARRAY_SIZE = 20;
const int RANGE_SIZE = 11;

/* Private Prototype Function */

string PrintAsterisk(int);
int Max(int array[]);
void HistogramSize(int[], int[]);
void LoadArray(int[]);

/* Main Function */

int main() {
    int array[] = {0, 67, 9, 21, 34, 78, 99, 80, 100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80};
    int size[RANGE_SIZE];
    
    LoadArray(size);
    HistogramSize(array, size);
    int max = Max(size);

    // Horizontal Histogram
     cout << "\t Histogram" << endl;
    for (int i = 0; i < RANGE_SIZE; i++)
        cout << "  " << i * 10 << ": " << PrintAsterisk(size[i]) << endl;

    // Vertical Histogram
    for (int i = max; i >= 0; i--) {
        for (int k = 0; k < RANGE_SIZE; k++) {
            if (size[k] > i) cout << "*";
            else cout << " ";
            cout << "   ";
        }
        cout << endl;
    }

    for (int i = 0; i < RANGE_SIZE; i++)
        cout << i * 10 << "  ";
    
    cout << endl;
    return 0;
}


/* 
 * Function: LoadArray()
 * Usage: LoadArray(int arr[])
 * ---------------------------------------------
 * This takes an array and loads the array with zeros.
*/

void LoadArray(int array[]) {
    for (int i = 0; i < RANGE_SIZE; i++) {
        array[i] = 0;
    }
}

/* 
 * Function: PrintAsterisk()
 * Usage: PrintAsterisk(int n)
 * ---------------------------------------------
 * This takes a number and prints the corresponding 
 * number of asterisks.
*/

string PrintAsterisk(int n) {
    string str = " ";
    for (int i = 0; i < n; i++)
        str += "* ";
    return str;
}

/*
* Function: Max
* Usage: max = Max(array);
* -----------------------------
* This function returns the maximum element in an array.
*/

int Max(int array[]) {
    int max = array[0];

    for (int i = 1; i < RANGE_SIZE; i++) {
        if (max < array[i]) max = array[i];
    }
    return max;
}

/* 
 * Function: HistogramSize()
 * Usage: HistogramSize(int[], int[], int n)
 * ---------------------------------------------
 * This takes 2 arrays and fills one with the number of elements in 
 * some range in one array into the other array.
*/

void HistogramSize(int array[], int size[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        switch (array[i]) {
            case 0 ... 9:
                size[0] += 1;
                break;
            case 10 ... 19:
                size[1] += 1;
                break;
            case 20 ... 29:
                size[2] += 1;
                break;
            case 30 ... 39:
                size[3] += 1;
                break;
            case 40 ... 49:
                size[4] += 1;
                break;
            case 50 ... 59:
                size[5] += 1;
                break;
            case 60 ... 69:
                size[6] += 1;
                break;
            case 70 ... 79:
                size[7] += 1;
                break;
            case 80 ... 89:
                size[8] += 1;
                break;
            case 90 ... 99:
                size[9] += 1;
                break;
            case 100:
                size[10] += 1;
                break;
            default:
                cout << "Unknown score" << endl;
                break;
        }
    }
}