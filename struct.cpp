#include <iostream>
using namespace std;

struct employeeRecordT {
    string name;
    int salary;
    string ssn;
};


int main() {
    employeeRecordT *emp = new employeeRecordT;
    employeeRecordT manager = {
        "Kevin", 45, "34-42DE-87"
    };

    emp->name = "Christian";
    emp->salary = 8848;
    emp->ssn = "S34-42DE-87";

    cout << emp->name << " " << emp->salary << " " << emp->ssn << endl;
    cout << manager.name << " " << manager.salary << " " << manager.ssn << endl;
    return 0; 
}