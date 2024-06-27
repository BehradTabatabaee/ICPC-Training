#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int ts = 1; ts <= n; ts++) {
        string s, t;
        cin >> s >> t;

        int s0 = 0, s1 = 0, t0 = 0, t1 = 0, sq= 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] != '?')
                s1 += s[i] - '0';
            else sq++;
            t1 += t[i] - '0';
        }
        s0 = len - s1, t0 = len - t1;

        if (s1 > t1) {
            cout << "Case " << ts << ": " << -1 << endl;
            continue;
        }

        int res = sq, z2o = 0, o2z = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '?') continue;
            if (s[i] != t[i]) {
                if (s[i] == '0') z2o++;
                else o2z++;
            }
        }

        res += max(z2o, o2z);
        cout << "Case " << ts << ": " << res << endl;
    }

    return 0;
}