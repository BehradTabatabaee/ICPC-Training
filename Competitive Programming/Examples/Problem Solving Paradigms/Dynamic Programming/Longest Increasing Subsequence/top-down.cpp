#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

int LIS(vector<int>& nums, int j, int i = -1) {
    if (j == nums.size()) {
        return 0;
    }

    if (i != -1 && dp[i][j] != -1) {
        return dp[i][j];
    }

    int taken = 0;
    if (i == -1 || nums[j] > nums[i]) {
        taken = 1 + LIS(nums, j + 1, j);
    }

    int notTaken = LIS(nums, j + 1, i);

    int ans = max(taken, notTaken);

    if (i != -1) {
        dp[i][j] = ans;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    dp.resize(n, vector<int>(n, -1));
    int len = 0;
    for (int i = 0; i < n; i++) {
        len = max(len, LIS(nums, i));
    }
    cout << len << endl;
    return 0;
}
