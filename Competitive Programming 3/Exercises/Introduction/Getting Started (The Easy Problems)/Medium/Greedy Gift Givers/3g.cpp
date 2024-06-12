#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    const string given = "given";
    const string taken = "taken";
    int motherF = 0;

    while (true) {
        int n;
        if (!(cin >> n)) {
            break;
        }
        if (motherF != 0) {
            cout << endl;
        }
        cin.ignore();

        map<string, map<string, int>> friends;
        string line;
        getline(cin, line);
        istringstream namesStream(line);
        vector<string> names;
        string name;

        while (namesStream >> name) {
            names.push_back(name);
            friends[name][given] = 0;
            friends[name][taken] = 0;
        }

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            istringstream queryStream(line);
            string giver;
            int amount, num;
            queryStream >> giver >> amount >> num;

            int mon = (num != 0) ? amount / num : 0;
            friends[giver][given] = (mon * num);

            for (int j = 0; j < num; ++j) {
                string receiver;
                queryStream >> receiver;
                friends[receiver][taken] += mon;
            }
        }

        for (const string& name : names) {
            cout << name << " " << (friends[name][taken] - friends[name][given]) << endl;
        }
        motherF += 1;
    }
    return 0;
}
