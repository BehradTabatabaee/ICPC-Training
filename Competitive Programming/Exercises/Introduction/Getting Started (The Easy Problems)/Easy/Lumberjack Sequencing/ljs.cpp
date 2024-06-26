#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isSortedAscending(vector <int> v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isSortedDescending(vector <int> v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << "Lumberjacks:" << endl;
    for (int i = 0; i < n; i++) {
        vector <int> lumbers;
        for (int j = 0; j < 10; j++) {
            int lumber;
            cin >> lumber;
            lumbers.push_back(lumber);
        }
        if (isSortedAscending(lumbers) || isSortedDescending(lumbers)) {
            cout << "Ordered" << endl;
        }
        else {
            cout << "Unordered" << endl;
        }
    }
    return 0;
}