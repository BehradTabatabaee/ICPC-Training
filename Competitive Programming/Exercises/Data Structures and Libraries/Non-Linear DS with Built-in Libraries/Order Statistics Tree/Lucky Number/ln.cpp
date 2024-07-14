#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> ost;

#define MAXN 2000000

unordered_map<int, pair<int,int>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ost os;
    int i = 1;
    while (i <= MAXN) {
        os.insert(i);
        i += 2;
    }
    ost::iterator it = os.begin();
    advance(it, 1);
    for (it; it != os.end(); it++) {
        int num = *it;
        for (int j = num - 1; j < os.size(); j += num - 1) {
            os.erase(os.find_by_order(j));
        }
    }
    bitset<MAXN> isInTree;
    for (auto i : os) {
        isInTree[i] = 1;
    } 
    int n;
    while (cin >> n) {
        if (n % 2 == 1) {
            cout << n << " is not the sum of two luckies!" << endl;
            continue;
        }
        if (dp.count(n)) {
            cout << n << " is the sum of " << dp[n].first << " and " << dp[n].second << "." << endl;
            continue;
        }
        int min = -1;
        for (int i = n / 2; i >= 1; i--) {
            if (isInTree[i] && isInTree[n - i]) {
                min = i;
                cout << n << " is the sum of " << i << " and " << n - i << "." << endl;
                dp[n] = make_pair(i, n - i);
                break;
            }
        }
        if (!min) {
            cout << n << " is not the sum of two luckies!" << endl;
        }

    }

    return 0;
}