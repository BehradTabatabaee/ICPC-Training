#include <iostream>
#include <map>
#include <set>
#include <list>
#include <unordered_map>

using namespace std;

struct TeamInfo {
    int wins;
    int points;
    int id;

    bool operator<(const TeamInfo& other) const {
        if (wins != other.wins) {
            return wins > other.wins;
        } else if (points != other.points) {
            return points < other.points;
        } else {
            return id < other.id;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    std::map<int, TeamInfo> teams;
    std::list<TeamInfo> rankList;
    std::unordered_map<int, std::list<TeamInfo>::iterator> teamIterators;

    auto insertOrUpdate = [&](int t, int p) {
        auto it = teams.find(t);
        if (it != teams.end()) {
            rankList.erase(teamIterators[t]);
            it->second.wins++;
            it->second.points += p;
        } else {
            teams[t] = {1, p, t};
        }
        auto iter = std::lower_bound(rankList.begin(), rankList.end(), teams[t]);
        teamIterators[t] = rankList.insert(iter, teams[t]);
    };

    teams[1] = {0, 0, 1};
    auto iter = std::lower_bound(rankList.begin(), rankList.end(), teams[1]);
    teamIterators[1] = rankList.insert(iter, teams[1]);

    for (int i = 0; i < m; i++) {
        int t, p;
        cin >> t >> p;
        insertOrUpdate(t, p);

        int rank = 1;
        for (const auto& team : rankList) {
            if (team.id == 1) {
                break;
            }
            rank++;
        }

        std::cout << rank << std::endl;
    }

    return 0;
}
