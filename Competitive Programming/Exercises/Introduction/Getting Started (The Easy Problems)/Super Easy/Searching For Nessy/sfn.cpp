#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int row, col;
        cin >> row >> col;
        cout << ((row - 2 + 2) / 3) * ((col - 2 + 2) / 3) << endl;
    }
    return 0;
}
