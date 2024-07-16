#include <iostream>
#include <map>
#include <set>

using namespace std;

struct PairComparator {
    bool operator()(const pair<int, pair<int, int>>& lhs, const pair<int, pair<int, int>>& rhs) const {
        if (lhs.second.first != rhs.second.first) {
            return lhs.second.first > rhs.second.first;
        } else if (lhs.second.second != rhs.second.second) {
            return lhs.second.second < rhs.second.second;
        } else {
            return lhs.first < rhs.first;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    std::map<int, pair<int, int>> teams;
    std::set<pair<int, pair<int, int>>, PairComparator> ranks;

    auto insertOrUpdate = [&](int t, int p) {
        auto it = teams.find(t);
        if (it != teams.end()) {
            ranks.erase({t, it->second});
            it->second.first++;
            it->second.second += p;
            ranks.insert({t, it->second});
        } else {
            teams[t] = {1, p};
            ranks.insert({t, teams[t]});
        }
    };

    teams[1] = {0, 0};
    ranks.insert({1, teams[1]});

    for (int i = 0; i < m; i++) {
        int t, p;
        cin >> t >> p;
        insertOrUpdate(t, p);

        int rank = 1;
        for (const auto& pair : ranks) {
            if (pair.first == 1) {
                break;
            }
            rank++;
        }

        std::cout << rank << std::endl;
    }

    return 0;
}
