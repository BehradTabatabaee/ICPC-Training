#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int j = 1;
    while (n != 0) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num > 0) {
                count++;
            }
            else {
                count--;
            }
        }
        cout << "Case " << j++ << ": " << count << endl;
        cin >> n;
    }
    return 0;
}