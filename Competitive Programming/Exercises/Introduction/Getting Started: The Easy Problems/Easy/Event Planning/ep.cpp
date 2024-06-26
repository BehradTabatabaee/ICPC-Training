#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int people,budget,hotels,weeks;
    while (cin >> people >> budget >> hotels >> weeks) {
        vector <int> h;
        for (int i = 0; i < hotels; i++) {
            int cost;
            cin >> cost;
            for (int j = 0; j < weeks; j++) {
                int size;
                cin >> size;
                if (size >= people) {
                    h.push_back(cost);
                }
            }
        }
        if (!h.empty()) {
            vector<int>::iterator min = min_element(h.begin(), h.end());
            if (((*min) * people) <= budget) {
                cout << *min * people << endl;
            }
            else {
                cout << "stay home" << endl;
            }
        }
        else {
            cout << "stay home" << endl;
        }
    }
    return 0;
}