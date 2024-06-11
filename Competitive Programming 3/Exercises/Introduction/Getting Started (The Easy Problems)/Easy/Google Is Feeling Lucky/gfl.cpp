#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int maxElement(vector<pair<string,int>> v) {
    int max = INT_MIN;
    for (auto i : v) {
        if (i.second >= max) {
            max = i.second;
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<pair<string,int>> websites;
        for (int j = 0; j < 10; j++) {
            string website;
            cin >> website;
            int relevance;
            cin >> relevance;
            websites.push_back(make_pair(website,relevance));
        }
        cout << "Case #" << i + 1 << ":" << endl;
        int max = maxElement(websites);
        for (int j = 0; j < 10; j++) {
            if (websites[j].second == max) {
                cout << websites[j].first << endl;
            }
        }
    }
    return 0;
}