#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int test = 1;
    while (getline(cin,s)) {
        int cases;
        cin >> cases;
        cout << "Case " << test++ << ":" << endl;
        for (int i = 0; i < cases; i++) {
            int l,r;
            bool flag = true;
            cin >> l >> r;
            cin.ignore();
            int start = min(l,r);
            int e = max(l,r);
            char c = s[start];
            for (int j = start + 1; j <= e; j++) {
                if (s[j] != c) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}