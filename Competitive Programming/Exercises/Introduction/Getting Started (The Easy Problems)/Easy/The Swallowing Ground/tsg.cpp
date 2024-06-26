#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        int a, b;
        cin >> a >> b;
        int val = a - b;
        bool flag = false;
        for (int j = 1; j < w; j++) {
            cin >> a >> b;
            if (!flag && val == (a - b)) {
                continue;
            }
            else {
                flag = true;
            }
        }
        if (!flag) {
            cout << "yes" << endl;
        } 
        else {
            cout << "no" << endl;
        }
        if (i != n - 1) cout << endl;
    }
}