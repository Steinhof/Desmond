#ifndef DESMOND_KMEANS_H
#define DESMOND_KMEANS_H

#include <iostream>
#include <valarray>
#include <cmath>

using namespace std;

class KMeans {

public:
    KMeans() = default;;

    ~KMeans() = default;

    KMeans(int k, vector<pair<double, double>> &data) : m_k(k), m_means(k), m_data(k) {
        m_data[0] = data;
    }

    void clusterData(valarray<pair<double, double>> *init_means, int num_iterations);

    void printClusters() const;

private:
    int m_k = 0;
    int m_features = 0;
    valarray<pair<double, double>> m_means; // container to hold current means
    valarray<vector<pair<double, double>>> m_data; // array of vectors

    bool computeMeans() {
        // true if means are same as previous iteration
        bool result = true;

        for (int i = 0; i < m_k; ++i) {
            pair<double, double> mean(0, 0);
            int num_features_of_k = m_data[i].size();
            for (auto const &item : m_data[i]) {
                get<0>(mean) += get<0>(item);
                get<1>(mean) += get<1>(item);
            }

            get<0>(mean) /= num_features_of_k;
            get<1>(mean) /= num_features_of_k;

            result = (m_means[i] == mean && result);
            m_means[i] = mean;

            cout << "Cluster" << i << get<0>(mean) << "," << get<1>(mean) << endl;
        };
        return result;
    };

    void assignLabels() {
        valarray<vector<pair<double, double>>> new_data(m_k);

        for (auto const &cluster : m_data) {
            for (auto const &feature : cluster) {
                int closet_mean = this->computeClosetCentroid(feature);
                new_data[closet_mean].push_back(feature);
            }
        }
        m_data = new_data;
    };

    int computeClosetCentroid(const pair<double, double> &point) const {
        valarray<double> distances(m_k);

        for (int k = 0; k < m_k; ++k) {
            double del_x = get<0>(point) - get<0>(m_means[k]);
            double del_y = get<1>(point) - get<1>(m_means[k]);

            double dist = sqrt(pow(del_x, 2) + pow(del_y, 2));
            distances[k] = dist;
        }
        auto closet_mean = distance(begin(distances), min_element(begin(distances), end(distances)));
        return closet_mean;
    };
};


#endif
