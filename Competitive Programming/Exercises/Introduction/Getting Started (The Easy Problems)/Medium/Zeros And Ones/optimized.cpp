#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int table[1000000];
    int num[1000000];
    table[0] = 0;
    char c;
    int size = 0;
    int ca = 1;
    while (c = cin.get()) {
        if (c == EOF) break;
        else if (c != '\n') {
            if (c == '0') {
                table[size] = size? 0 + table[size - 1] : 0;
                num[size] = 0;
            }
            if (c == '1') {
                table[size] = size? 1 + table[size - 1] : 1;
                num[size] = 1;
            }
            size++;
        } else {
            cout << "Case " << ca++ << ":" << endl;
            int cases;
            cin >> cases;
            for (int i = 0; i < cases; i++) {
                int a, b;
                cin >> a >> b; cin.ignore();
                int ma = max(a, b);
                int mi = min(a, b);
                int r = table[ma] - table[mi];
                if ((r == 0 || r == (ma - mi)) && num[a] == num[b]) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
            size = 0;
        }
    }
    return 0;
}