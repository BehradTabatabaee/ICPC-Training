#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    for (int i = 1; i < n; i++) {
        int m = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                m = max(dp[j], m);
        }
        dp[i] = max(m + 1, dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}