/* 
 * File: sieve_of_erato.cpp
 * --------------------------
 * This program generates a list of the primes between
 *  2 and 1000 using the sieve of Eratosthenes. 
 */

#include <iostream>
using namespace std;

/* Constants */

const int ARRAY_SIZE = 999;

/* Private Prototype Functions */
void LoadArray(int[], int);
void SievePrime(int[], int);


/* Main Function */

int main() {
    int *arr = new int[ARRAY_SIZE];
    LoadArray(arr, ARRAY_SIZE);
    SievePrime(arr, ARRAY_SIZE);

    cout << "[ ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == 0) continue;
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}

/* 
 * Function: LoadArray()
 * Usage: LoadArray(int arr[], int n)
 * ---------------------------------------------
 * This takes an array and effective size n, and 
 * loads in values from 2 to n;
*/

void LoadArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i + 2;
    }
}

/* 
 * Function: SievePrime()
 * Usage: SievePrime(int arr[], int n)
 * -----------------------------------------------------------
 * This takes an array and effective size n, and 
 * produces the primes from 2 to n using sieve of Eratosthenes;
*/

void SievePrime(int array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] == 0) continue; 
            if (array[j] % array[i] == 0) array[j] = 0;
        }
    }
}