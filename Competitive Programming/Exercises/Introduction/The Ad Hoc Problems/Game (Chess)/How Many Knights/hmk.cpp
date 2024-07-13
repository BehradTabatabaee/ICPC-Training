#include <iostream>
#include <math.h>
using namespace std;

int maxKnights(int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (m == 1 || n == 1) {
        return m * n;
    }
    if (m == 2 || n == 2) {
        int major = max(m, n);
        if (major % 4 == 0) return major;
        if (major % 4 == 1 || major % 4 == 3) return major + 1;
        if (major % 4 == 2) return major + 2;
    }
    // THIS SHIT AGAIN, FUCKING FLOATING POINT DIVISION...
    return (m * n + 1) / 2;
}

int main() {
    int m, n;
    cin >> m >> n;
    while (m != 0 || n != 0) {
        int result = maxKnights(m, n);
        cout << result << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        cin >> m >> n;
    }
    return 0;
}
