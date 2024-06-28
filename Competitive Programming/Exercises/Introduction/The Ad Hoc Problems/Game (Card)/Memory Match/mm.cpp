#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define forr(i, a, b) for(int i = a; i < b; i++)
#define us unordered_set
#define um unordered_map
#define v(s) vector<s>
#define vs v(string)
#define vb v(bool)
#define pb push_back

int main() {
    int n, k;
    cin >> n >> k;
    vb up(n + 1, false);
    vs cards(n + 1, "A");
    um<string, us<int>> state;
    forr(i, 0, k) {
        int c1, c2;
        string p1, p2;
        cin >> c1 >> c2 >> p1 >> p2;
        cards[c1] = p1;
        cards[c2] = p2;
        state[p1].insert(c1);
        state[p2].insert(c2);
        if (p1 == p2) {
            up[c1] = true;
            up[c2] = true;
        }
    }
    int unknown = 0;
    int ones = 0;
    int score = 0;
    us<string> counted;
    forr(i, 1, n + 1) {
        string card = cards[i];
        if (up[i] == true) continue;
        if (card == "A") {
            unknown++;
            continue;
        }
        if (state[card].size() == 2 && counted.count(card) == 0) {
            counted.insert(card);
            score++;
            continue;
        } 
        if (state[card].size() == 1) {
            ones++;
        }
    }
    if (unknown <= ones) score += ones;
    else if (unknown == 2) score++;
    cout << score << endl;
    return 0;
}