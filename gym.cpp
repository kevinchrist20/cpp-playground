/*
* File: gymjudge.cpp
* ------------------
* This program averages a set of gymnastic scores.
*/

#include <iostream>
#include "simpio.h"
#include "error.h"

using namespace std;

/* Constants */

const int MAX_JUDGES = 100;
const double MIN_SCORE = 0.0;
const double MAX_SCORE = 10.0;

/* Private function prototypes */

void ReadAllScores(double scores[], int nJudges);
double GetScore(int judge);
double Mean(double array[], int n);
double Max(double array[], int n);
double Min(double array[], int n);
bool DoubleEquals(double, double, double epsilon = 0.001);

/* Main program */

int main() {
    double scores[MAX_JUDGES];
    cout << "Enter number of judges: ";
    int nJudges = getInteger();

    if (nJudges > MAX_JUDGES) error("Too many judges");
    ReadAllScores(scores, nJudges);
    cout << "The average score is " << Mean(scores, nJudges) << endl;

    return 0;
}

/*
* Function: ReadAllScores
* Usage: ReadAllScores(scores, nJudges);
* --------------------------------------
* This function reads in scores for each of the judges. The
* array scores must be declared by the caller and must have
* an allocated size that is at least as large as nJudges.
* Because people tend to count starting at 1 rather than 0,
* this program adds 1 to the argument to GetScore, which means
* that the values the user sees will range from 1 to n instead
* of between 0 and n-1.
*/

void ReadAllScores(double scores[], int nJudges) {
    for (int i = 0; i < nJudges; i++) {
        scores[i] = GetScore(i + 1);
    }
}

/*
* Function: GetScore
* Usage: score = GetScore(judge);
* -------------------------------
* This function reads in the score for the specified judge.
* The implementation makes sure that the score is in the
* legal range before returning.
*/

double GetScore(int judge) {
    while (true) {
        cout << "Score for judge #" << judge << ": ";
        double score = getReal();
        if (score >= MIN_SCORE && score <= MAX_SCORE) return score;
        cout << "That score is out of range. Try again." << endl;
    }
}

/*
* Function: Mean
* Usage: mean = Mean(array, n);
* -----------------------------
* This function returns the statistical mean (average) of a
* distribution stored in array, which has effective size n.
*/

double Mean(double array[], int n) {
    double total = 0;
    double min = Min(array, n);
    double max = Max(array, n);

    for (int i = 0; i < n; i++) {
        if (DoubleEquals(min, array[i]) || DoubleEquals(max, array[i]))
            continue;
        total += array[i];
    }
    return total / (n - 2);
}

/*
* Function: Min
* Usage: min = Max(array, n);
* -----------------------------
* This function returns the minimum element in an array,
* which has effective size n.
*/

double Min(double array[], int n) {
    double min = array[0];

    for (int i = 1; i < n; i++) {
        if (min > array[i]) min = array[i];
    }
    return min;
}


/*
* Function: Max
* Usage: max = Max(array, n);
* -----------------------------
* This function returns the maximum element in an array,
* which has effective size n.
*/

double Max(double array[], int n) {
    double max = array[0];

    for (int i = 1; i < n; i++) {
        if (max < array[i]) max = array[i];
    }
    return max;
}

/*
* Function: DoubleEquals
* Usage: equal = DoubleEquals(array, n);
* -----------------------------
* This function returns the equality between two doubles.
*/

bool DoubleEquals(double a, double b, double epsilon) {
    return abs(a - b) < epsilon;
}
