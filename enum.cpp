#include <iostream>
using namespace std;

enum directionT {
    North, East, West, South
};

directionT RightFrom(directionT);
directionT LeftFrom(directionT);
string directionName(directionT);

int main() {
    directionT dir = North;

    cout << "Current direction = " << directionName(dir) << endl;
    cout << "Direction Right from " << directionName(dir) << " = " << directionName(RightFrom(dir))<< endl;
    cout << "Direction Left from " << directionName(dir) << " = " << directionName(LeftFrom(dir))<< endl;
    return 0;
}

directionT RightFrom(directionT dir) {
    return directionT((dir + 1) % 4);
}

directionT LeftFrom(directionT dir) {
    return directionT((dir + 4 - 1) % 4);
}

string directionName(directionT dir) {
    switch(dir) {
        case North: return "North";
        case East: return "East";
        case West: return "South";
        case South: return "West";
        default: return "Illegal direction value";
    }
}