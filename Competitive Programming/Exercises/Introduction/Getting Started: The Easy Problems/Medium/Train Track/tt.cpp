#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin,s);
        int size = s.size();
        int firstMCount = 0, lastMCount = 0, firstFCount = 0, lastFCount = 0;
        string str = "";
        for (int i = 0; i < size; i++) {
            if (s[i] == ' ' || i == size - 1) {
                if (i == size - 1) {
                    str += s[i];
                }
                if (str[0] == 'F') {
                    firstFCount++;
                }
                if (str[1] == 'M') {
                    lastMCount++;
                }
                if (str[0] == 'M') {
                    firstMCount++;
                }
                if (str[1] == 'F') {
                    lastFCount++;
                }
                str = "";
            }
            else {
                str += s[i];
            }
        }
        if (firstFCount == lastMCount && firstMCount == lastFCount && size > 3) {
            cout << "LOOP" << endl;
        }
        else {
            cout << "NO LOOP" << endl;
        }
    }
    return 0;
}