#include <iostream>
using namespace std;

void ReverseArray(int [], int);

int main() {
    int myArray[] = {2, 3, 1, -8, 0, 1};
    int _size = sizeof(myArray) / sizeof(int);
    ReverseArray(myArray, _size);

    for (int i = 0; i < _size; i++)
        cout << myArray[i] << " ";

    cout << endl;
    return 0;
}

void ReverseArray(int arr[], int _size) {
    for(int i = 0; i < _size / 2; i++) {
        int other = _size - i - 1;
        int temp = arr[i];
        arr[i] = arr[other];
        arr[other] = temp;
    }
}
