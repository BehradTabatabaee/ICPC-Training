#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != 0)
    {
        int x,y;
        cin >> x >> y;
        for (int i = 0; i < n; i++) {
            int a,b;
            cin >> a >> b;
            if (a == x || b == y) {
                cout << "divisa" << endl;
            }
            else if (a < x && b < y) {
                cout << "SO" << endl;
            }
            else if (a < x && b > y) {
                cout << "NO" << endl;
            }
            else if (a > x && b < y) {
                cout << "SE" << endl;
            }
            else if (a > x && b > y) {
                cout << "NE" << endl;
            }
        }
        cin >> n;
    }
    
    return 0;
}