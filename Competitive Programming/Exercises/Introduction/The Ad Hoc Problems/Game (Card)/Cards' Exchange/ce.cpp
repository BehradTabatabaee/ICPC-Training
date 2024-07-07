#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    while (a != 0 && b != 0) {
        unordered_set<int> ac, bc;
        for (int i = 0; i < a; i++) {
            int card;
            cin >> card;
            ac.insert(card);
        }
        for (int i = 0; i < b; i++) {
            int card;
            cin >> card;
            bc.insert(card);
        }
        int acnotbc = 0, bcnotac = 0;
        for (auto i : ac) {
            if (bc.count(i) == 0) {
                acnotbc++;
            }
        }
        for (auto i : bc) {
            if (ac.count(i) == 0) {
                bcnotac++;
            }
        }
        cout << min(acnotbc,bcnotac) << endl;
        cin >> a >> b;
    }
    return 0;
}