#include <iostream>
using namespace std;

int main() {
    int squares[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_size = sizeof(squares) / sizeof(squares[0]);

    for (int i = 1; i < arr_size; i++)
        squares[i] = squares[i] * squares[i];

    cout << "[ ";
    for (int i = 0; i < arr_size; i++)
        cout << squares[i] << " ";
    cout << "]" << endl;
    return 0;
}