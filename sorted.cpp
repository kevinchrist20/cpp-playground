/*
* File: sorted.cpp
* ------------------
* This program checks an array is sorted in nondecreasing order.
*/

#include <iostream>
using namespace std;

/* Private Prototype Functions */

bool IsSorted(int[], int);

/* Main Function */

int main() {
    int a[] = {1, 3, 5, 7, 8, 10, 89};
    int b[] = {76, 9, 4, 3, 2, 0, -1};

    if (IsSorted(a, 7)) cout << "Array A => sorted" << endl;
    else cout << "Array A => not sorted" << endl;

    if (IsSorted(b, 7)) cout << "Array B => sorted" << endl;
    else cout << "Array B => not sorted" << endl;
    
    return 0;
}

/* 
 * Function: IsSorted
 * Usage: IsSorted(int array[], int n);
 * -------------------------------------
 * This takes an array and its effective size, and 
 * determines whether the function is sorted in nondecreasing
 * order.
*/

bool IsSorted(int array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) return false;
        }
    }
    return true;
}