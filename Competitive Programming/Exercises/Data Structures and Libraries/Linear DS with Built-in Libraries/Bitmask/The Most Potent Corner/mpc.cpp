#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>
using namespace std;

vector<int> neighbourCalc(int n, int dimensions) {
    vector<int> neighbours;
    for (int i = 0; i < dimensions; i++) {
        neighbours.push_back(n ^ (1 << i));
    }
    return neighbours;
}

int main() {
    int n;
    while (cin >> n) {
        int cornerCount = pow(2, n);
        vector<int> weights(cornerCount);
        for (int i = 0; i < cornerCount; i++) {
            int weight;
            cin >> weight;
            weights[i] = weight;
        }

        vector<int> potencies(cornerCount);
        vector<vector<int>> neighbours(cornerCount, vector<int>(n));

        for (int i = 0; i < cornerCount; i++) {
            neighbours[i] = neighbourCalc(i, n);
        }

        for (int i = 0; i < cornerCount; i++) {
            int potency = 0;
            for (int j = 0; j < neighbours[i].size(); j++) {
                potency += weights[neighbours[i][j]];
            }
            potencies[i] = potency;
        }

        int max = INT_MIN;

        for (int i = 0; i < cornerCount; i++) {
            for (int j = 0; j < neighbours[i].size(); j++) {
                if (potencies[i] + potencies[neighbours[i][j]] >= max)
                    max = potencies[i] + potencies[neighbours[i][j]];
            }
        }

        cout << max << endl;

    }
    return 0;
}