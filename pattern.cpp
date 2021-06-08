#include <iostream>
using namespace std;

int main() {

    int num_rows;
    cout << "Enter number of rows: ";
    cin >> num_rows;

    // Top pattern
    for (int row = 1; row <= num_rows; row++)
    {
        for (int num = 1; num <= row; num++)
            cout << num;
        cout << endl;
    }

    cout << endl;
    cout << endl;

    // Down pattern
    for (int row = num_rows; row >= 1; row--)
    {
        for (int num = 1; num <= row; num++)
            cout << num;
        cout << endl;
    }

    cout << endl;
    cout << endl;

    // Full
    for (int row = 1; row <= num_rows; row++)
    {
        // Spaces
        for (int spaces = 2 * (num_rows - row); spaces >= 1; spaces--) 
            cout << " ";

        // Nth number of rows
        for (int num = row; num <= (row + (row - 1)); num++)
            cout << num << " ";

        // last n-1 number
        for (int second = (row + (row - 1)) - 1; second >= row; second--)
            cout << second << " ";

        cout << endl;
    }
    
    
    return 0;
}