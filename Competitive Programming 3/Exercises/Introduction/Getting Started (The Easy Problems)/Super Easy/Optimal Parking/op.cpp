#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int shops;
        cin >> shops;
        vector<int> x(shops);
        for (int i = 0; i < shops; i++) {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int dist = 0;
        for (int i = 1; i < shops; i++) {
            dist += x[i] - x[i - 1];
        }
        cout << dist * 2 << endl;  // Multiply by 2 because he needs to walk back to the car
    }
    return 0;
}
