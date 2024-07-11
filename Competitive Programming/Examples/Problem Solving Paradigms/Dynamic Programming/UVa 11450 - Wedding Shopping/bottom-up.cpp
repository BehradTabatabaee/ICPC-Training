#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<vector<bool>> dp;

int main() {
    int n;
    cin >> n;
    for (int tc = 0; tc < n; tc++) {
        int budget, garments;
        cin >> budget >> garments;
        dp.clear();
        dp.resize(budget + 1, vector<bool>(garments, 0));
        vector<vector<int>> prices(garments, vector<int>());
        for (int i = 0; i < garments; i++) {
            int num;
            cin >> num;
            prices[i].resize(num);
            for (int j = 0; j < num; j++) {
                int price;
                cin >> price;
                prices[i][j] = price;
            }
        }
        for (int i = 0; i < prices[0].size(); i++) {
            if (prices[0][i] <= budget)
                dp[prices[0][i]][0] = true;
        }
        for (int i = 1; i < garments; i++) {
            for (int j = 0; j <= budget; j++) {
                for (int k = 0; k < prices[i].size(); k++) {
                    if (j - prices[i][k] >= 0)
                        if(dp[j - prices[i][k]][i - 1]) {
                            dp[j][i] = true;
                            break;
                        }
                }
            }
        }
        bool hasAns = false;
        for (int i = budget; i >= 0; i--) {
            if (dp[i][garments - 1]) {
                cout << i << endl;
                hasAns = true;
                break;
            }
        }
        if (!hasAns) {
            cout << "no solution" << endl;
        }
    }
    return 0;
}
