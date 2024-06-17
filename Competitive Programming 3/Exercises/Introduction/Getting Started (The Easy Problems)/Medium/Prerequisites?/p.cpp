#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define v(i) vector<i>
#define vi v(int)
#define vs v(string)
#define vvs v(v(string))
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)

int main() {
    int k, m, c, r;
    string id;
    while (cin >> k) {
        if (k == 0) break;
        cin >> m;
        vvs cats(m, vs());
        vi req;
        vs taken;
        fori(k) {
            cin >> id;
            taken.push_back(id);
        }
        fori(m) {
            cin >> c >> r;
            req.push_back(r);
            forj(c) {
                cin >> id;
                cats[i].push_back(id);
            }
        }
        fori(k) {
            id = taken[i];
            forj(m) {
                auto it = find(cats[j].begin(), cats[j].end(), id);
                if (it != cats[j].end()) {
                    req[j]--;
                }
            }
        }
        bool flag = true;
        fori(m) {
            if (req[i] > 0) {
                cout << "no" << endl;
                flag = false;
                break;
            }
        }
        if (flag) cout << "yes" << endl;
    }
    return 0;
}