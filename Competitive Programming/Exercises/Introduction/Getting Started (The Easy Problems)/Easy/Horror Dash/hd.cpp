#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int students;
        cin >> students;
        int max = INT_MIN;
        for (int j = 0; j < students; j++) {
            int stud;
            cin >> stud;
            if (stud >= max) {
                max = stud;
            }
        }
        cout << "Case " << i + 1 << ": " << max << endl;
    }
    return 0;
}