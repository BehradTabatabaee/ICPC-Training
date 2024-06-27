#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n, i, j;
    while (cin >> n >> i >> j) {
        int r = 1;
        int b = max(i, j);
        int s = min(i, j);
        while (b - s > 1 || b % 2 == 1) {
            r++;
            b = ceil((double)b/2);
            s = ceil((double)s/2);
        }
        cout << r << endl;
    }
    return 0;
}