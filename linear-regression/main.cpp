#include <iostream>
#include <vector>
#include "regression.h"

int main(int argc, char **argv) {
    vector<double> y({2.8, 2.9, 7.6, 9, 8.6});
    vector<double> x({1, 2, 3, 4, 5});

    LinearRegression linearRegression(x, y);

    linearRegression.trainAlgorithm(1000, 3, -10);

    cout << linearRegression.regress(3) << endl;
}