#include <iostream>
using namespace std;

enum weekdayT {
    Mon, Tue, Wed, Thur, Fri, Sat, Sun
};

const int DAYS_IN_WEEK = 7;

weekdayT IncrementDay(weekdayT, int);
weekdayT NextDay(weekdayT);
weekdayT PreviousDay(weekdayT);
string DisplayDay(weekdayT);


int main() {
    weekdayT day = Thur;

    cout << "Today is " << DisplayDay(day) << ". Tomorrow is " << DisplayDay(NextDay(day)) << endl;
    cout << "Today is " << DisplayDay(day) << ". Yesterday was " << DisplayDay(PreviousDay(day)) << endl;
    cout << "Today is " << DisplayDay(day) << ". 10 days ago " << DisplayDay(IncrementDay(day, -10)) << endl;
    return 0;
}


weekdayT NextDay(weekdayT day) {
    return weekdayT(weekdayT(day + DAYS_IN_WEEK) % DAYS_IN_WEEK);
}

weekdayT PreviousDay(weekdayT day) {
    return weekdayT(weekdayT(day + DAYS_IN_WEEK - 1) % DAYS_IN_WEEK);
}

weekdayT IncrementDay(weekdayT startDay, int detal) {
    return weekdayT(weekdayT(startDay + DAYS_IN_WEEK + detal) % DAYS_IN_WEEK);
}

string DisplayDay(weekdayT day) {
    switch(day) {
        case Mon: return "Mon";
        case Tue: return "Tue";
        case Wed: return "Wed";
        case Thur: return "Thur";
        case Fri: return "Fri";
        case Sat: return "Sat";
        case Sun: return "Sun";
        default: return "Illegal value";
    }
}