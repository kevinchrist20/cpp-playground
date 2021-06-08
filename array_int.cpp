#include <iostream>
#include <algorithm>

// Find least positive integer in an array of numbers
using namespace std;

int GetPositiveIntIndex(int[], int);
int GetLeastPositiveInteger(int[], int);

int main()
{
    int myArr[] = {1, 3, 6, 4, 1, 2};
    int size = sizeof(myArr) / sizeof(int);
    cout << "The least missing positive integer: "
         << GetLeastPositiveInteger(myArr, size) << endl;
    return 0;
}

// Function to find the index of the first positive integer in the array
int GetPositiveIntIndex(int arr[], int size) {
    sort(arr, arr + size);

    for (int i = 0; i < size - 1; i++)
        if (arr[i] > 0)
            return i;
    return -1;
}

int GetLeastPositiveInteger(int arr[], int size) {
    int index = GetPositiveIntIndex(arr, size);

    if (index == -1)
        return 1;
    else {
        int j = 1;
        for (int i = index; i < size; i++) {
            if (i != j && !find(arr, arr + size, j))
                return j;
            j++;
        }
        return 1;
    }
}
