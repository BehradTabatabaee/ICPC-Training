#include <iostream>
#include <string>
using namespace std;

bool isOne(string s) {
    if (s[0] != 'o') {
        if (s[1] != 'n' || s[2] != 'e') {
            return false;
        }
        else {
            return true;
        }
    }
    if (s[1] != 'n') {
        if (s[0] != 'o' || s[2] != 'e') {
            return false;
        }
        else {
            return true;
        }
    }
    if (s[2] != 'e') {
        if (s[0] != 'o' || s[1] != 'n') {
            return false;
        }
        else {
            return true;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str.size() == 5) {
            cout << 3 << endl;
        }
        else if (str.size() == 3) {
            if (isOne(str)) {
                cout << 1 << endl;
            }
            else {
                cout << 2 << endl;
            }
        }
    }
    return 0;
}