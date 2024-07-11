#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasAns = false;

vector<vector<int>> dp;

int maxPrice(vector<vector<int>> prices, int budget, int i = 1) {
    if (i == prices.size()) {
        hasAns = true;
        return 0;
    }
    if (dp[budget][i] != -1) return dp[budget][i];
    int ans = 0;
    for (int j = 1; j < prices[i].size(); j++) {
        if (prices[i][j] <= budget) {
            ans = max(prices[i][j] + maxPrice(prices, budget - prices[i][j], i + 1), ans);
        }
    }
    return dp[budget][i] = ans;
}

int main() {
    int n;
    cin >> n;
    for (int tc = 0; tc < n; tc++) {
        int budget, garments;
        cin >> budget >> garments;
        hasAns = false;
        dp.clear();
        dp.resize(budget + 1, vector<int>(garments + 1, -1));
        vector<vector<int>> prices(garments + 1, vector<int>());
        for (int i = 1; i < garments + 1; i++) {
            int num;
            cin >> num;
            prices[i].resize(num + 1);
            for (int j = 1; j < num + 1; j++) {
                int price;
                cin >> price;
                prices[i][j] = price;
            }
        }
        int ans = maxPrice(prices, budget);
        if (hasAns) {
            cout << ans << endl;
        }
        else {
            cout << "no solution" << endl;
        }
    }
    return 0;
}