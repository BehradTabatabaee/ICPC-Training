#include <iostream>
#include <vector>
using namespace std;

int main() {
    int b, n;
    cin >> b >> n;
    while (b != 0 || n != 0) {
        vector <int> reserves;
        for (int i = 0; i < b; i++) {
            int r;
            cin >> r;
            reserves.push_back(r);
        }
        for (int i = 0; i < n; i++) {
            int b1,b2,val;
            cin >> b1 >> b2 >> val;
            reserves[b1 - 1] -= val;
            reserves[b2 - 1] += val;
        }
        for (int i = 0; i < reserves.size(); i++) {
            if (reserves[i] < 0) {
                cout << "N" << endl;
                goto end;
            }
        }
        cout << "S" << endl;
        end:
        cin >> b >> n;
    } 
    return 0;
}