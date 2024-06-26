#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        if (x <= 20 && y <= 20 && z <= 20) {
            cout << "Case " << i + 1 << ": good" << endl; 
        }
        else {
            cout << "Case " << i + 1 << ": bad" << endl;
        }
    }
    return 0;
}