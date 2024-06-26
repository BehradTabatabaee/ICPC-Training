#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 1;
    while (s != "*") {
        if (s == "Hajj") {
            cout << "Case " << i++ << ": Hajj-e-Akbar" << endl;
        }
        else {
            cout << "Case " << i++ << ": Hajj-e-Asghar" << endl;
        }
        cin >> s;
    }
    return 0;
}