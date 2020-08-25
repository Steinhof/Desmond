#include <cmath>
#include <iostream>
#include "kmeans.h"

int main(int argc, char **argv) {

    vector<pair<double, double>> data = {
            {1.1, 1},
            {1.4, 2},
            {3.8, 7},
            {5.0, 8},
            {4.3, 6},
            {8,   5.0},
            {6,   8.5},
            {3,   2.0},
            {9,   6},
            {9.1, 4}
    };

    KMeans km(3, data);

    auto *init_means = new valarray<pair<double, double>>{
            {1, 1},
            {3, 4},
            {8, 8}
    };

    km.clusterData(init_means, 1000);
    km.printClusters();
}