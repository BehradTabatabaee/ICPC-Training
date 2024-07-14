#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

int main() {
    int n, m;
    cin >> n >> m;
    
    auto comp = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) -> bool {
        if (a.second.first != b.second.first) {
            return a.second.first > b.second.first;
        } else if (a.second.second != b.second.second) {
            return a.second.second < b.second.second;
        } else {
            return a.first < b.first;
        }
    };
    
    typedef tree<pair<int, pair<int, int>>, null_type, decltype(comp), rb_tree_tag,
                 tree_order_statistics_node_update> ost;
    
    ost tree(comp);
    vector<pair<int, int>> teams(n + 1);
    
    for (int i = 0; i < n; i++) {
        tree.insert(make_pair(i + 1, make_pair(0, 0)));
        teams[i + 1] = make_pair(0, 0);
    }
    
    for (int i = 0; i < m; i++) {
        int team, penalty;
        cin >> team >> penalty;
        tree.erase(tree.find(make_pair(team, teams[team])));
        teams[team].first++;
        teams[team].second += penalty;
        tree.insert(make_pair(team, teams[team]));
        cout << tree.order_of_key(make_pair(1, teams[1])) + 1 << endl;
    }
    

    return 0;
}
