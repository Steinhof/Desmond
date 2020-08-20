#include <iostream>
#include <vector>
#include <cmath>

#ifndef DESMOND_REGRESSION_H
#define DESMOND_REGRESSION_H

using namespace std;

class LinearRegression {
public:
    LinearRegression() = default;

    ~LinearRegression() = default;

    LinearRegression(vector<double> &m_x_values, vector<double> &m_y_values) : m_x_values(m_x_values),
                                                                               m_y_values(m_y_values),
                                                                               m_num_elements(m_y_values.size()),
                                                                               m_old_error(
                                                                                       numeric_limits<double>::max()) {}

    void trainAlgorithm(int num_iterations, double a_initial, double b_initial);

    double regress(double x) const;

private:
    vector<double> m_x_values;
    vector<double> m_y_values;
    double m_num_elements;
    double m_old_error;
    double m_a;
    double m_b;

    bool isConverged();
};

#endif //DESMOND_REGRESSION_H
