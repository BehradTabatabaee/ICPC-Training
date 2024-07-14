#include <bits/stdc++.h>
using namespace std;

#define max 1000000

int main() {
    vector<vector<int>> arr(max);
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr[num].push_back(i + 1);
        }
        for (int i = 0; i < m; i++) {
            int k, num;
            cin >> k >> num;
            if (arr[num].size() > k - 1)
                cout << arr[num][k - 1] << endl;
            else 
                cout << 0 << endl;
        }
    }
    return 0;
}