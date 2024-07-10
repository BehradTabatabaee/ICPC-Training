#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<int> subsetSums;

void subsetSum(vector<int> bars, int i = 0, int sum = 0) {
    subsetSums.insert(sum);
    if (i >= bars.size()) return;
    subsetSum(bars, i + 1, sum + bars[i]);
    subsetSum(bars, i + 1, sum);
}

int main() {
    int n;
    cin >> n;
    for (int tc = 0; tc < n; tc++) {
        vector<int> bars;
        int sum, barNum;
        cin >> sum >> barNum;
        for (int i = 0; i < barNum; i++) {
            int bar;
            cin >> bar;
            bars.push_back(bar);
        }
        subsetSum(bars);
        if (subsetSums.count(sum) != 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        subsetSums.clear();
    }
    return 0;
}