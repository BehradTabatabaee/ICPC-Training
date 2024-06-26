#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "donate") {
            int num;
            cin >> num;
            sum += num;
        }
        else if (cmd == "report") {
            cout << sum << endl;
        }
    }
    return 0;
}