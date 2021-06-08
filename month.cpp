#include <iostream>
using namespace std;

enum monthT {
    Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

string displayMonth(monthT);

int main() {

    for (monthT month = Mar; month <= Dec; month = monthT(month + 1))
        cout << "We're in the month of " << displayMonth(month) << endl;

    return 0;
}


string displayMonth(monthT mon) {
    switch(mon) {
        case Jan: return "January";
        case Feb: return "February";
        case Mar: return "March";
        case Apr: return "April";
        case May: return "May";
        case Jun: return "June";
        case Jul: return "July";
        case Aug: return "August";
        case Sep: return "September";
        case Oct: return "October";
        case Nov: return "November";
        case Dec: return "December";
        default: return "Invalid month";
    }
}
