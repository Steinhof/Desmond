#include "kmeans.h"

void KMeans::clusterData(valarray<pair<double, double>> *init_means, int num_iterations) {
    this->m_means = *init_means;
    this->assignLabels();

    int i = 0;
    while (i < num_iterations) {
        cout << "iteration" << i << endl;
        this->assignLabels();
        this->computeMeans();
        i++;
    }
};

void KMeans::printClusters() const {
    for (int k = 0; k < m_k; ++k) {
        for (const auto &item : m_data[k]) {
            cout << get<0>(item) << "," << get<1>(item) << endl;
        }
    }
}


