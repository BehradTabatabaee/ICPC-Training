#include <iostream>
#include <string>
#include <vector>
using namespace std;

void move(int& x, vector<string> ins, int index) {
    if (ins[index] == "LEFT") {
        x--;
        return;
    }
    else if (ins[index] == "RIGHT") {
        x++;
        return;
    }
    else {
        move(x, ins, stoi(ins[index].substr(8)) - 1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        cin.ignore();
        vector<string> ins;
        for (int j = 0; j < m; j++) {
            string s;
            getline(cin,s);
            ins.push_back(s);
        }
        int x = 0;
        for (int j = 0; j < m; j++) {
            move(x,ins,j);
        }
        cout << x << endl;
    }
    return 0;
}