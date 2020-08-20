#include <iostream>
#include <cmath>
#include "regression.h"

void LinearRegression::trainAlgorithm(int num_iterations, double a_initial, double b_initial) {
    int iteration = 0;
    m_a = a_initial;
    m_b = b_initial;

    while (!isConverged() && iteration < num_iterations) {
        // update the gradient
        double step = 2 / double(iteration + 2);
        double a_gradient = 0;
        double b_gradient = 0;

        // compute gradient of a
        for (int i = 0; i < m_num_elements; i++) {
            a_gradient += m_x_values[i] * ((m_a * m_x_values[i] + m_b) - m_y_values[i]);
        }
        a_gradient = (2 * a_gradient) / m_num_elements;

        // compute gradient of b
        for (int i = 0; i < m_num_elements; i++) {
            b_gradient += ((m_a * m_x_values[i] + m_b) - m_y_values[i]);
        };
        b_gradient = (2 * a_gradient) / m_num_elements;

        m_a = m_a - (step * a_gradient);
        m_b = m_b - (step * b_gradient);

        cout << "a: \t" << m_a << endl;
        cout << "b: \t" << m_b << endl;
        cout << "gradient a:\t" << a_gradient << endl;
        cout << "gradient b:\t" << b_gradient << endl;

        iteration++;
    }
};


double LinearRegression::regress(double x) const {
    double regress = m_a * x + m_b;
    return regress;
}

bool LinearRegression::isConverged() {
    double error = 0;
    double threshold = 0.001;
    for (int i = 0; i < m_num_elements; i++) {
        error += pow(((m_a * m_x_values[i] + m_b) - m_y_values[i]), 2);
    }
    error /= m_num_elements;

    cout << "Error: " << error << endl;

    bool result = (abs(error) > m_old_error - threshold && abs(error) < m_old_error + threshold);
    m_old_error = abs(error);
    return result;
}