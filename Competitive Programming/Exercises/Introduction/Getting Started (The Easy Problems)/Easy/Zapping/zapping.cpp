#include <iostream>
#include <algorithm>
using namespace std;

int ascending(int a, int b) {
    int num = 0;
    while (a != b) {
        a++;
        num++;
        if (a > 99) {
            a = 0;
        }
    }
    return num;
}

int descending(int a, int b) {
    int num = 0;
    while (a != b) {
        a--;
        num++;
        if (a < 0) {
            a = 99;
        }
    }
    return num;
}

int main() {
    int a,b;
    cin >> a >> b;
    while (a >= 0 && b >= 0) {
        cout << min(ascending(a,b), descending(a,b)) << endl;
        cin >> a >> b;
    }
    return 0;
}