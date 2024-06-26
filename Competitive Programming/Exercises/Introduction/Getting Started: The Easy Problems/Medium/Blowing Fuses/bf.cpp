#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int main() {
    int n,m,c;
    cin >> n >> m >> c;
    int j = 1;
    while (n != 0 || m != 0 || c != 0) {
        vector <pair<int,bool>> devices;
        bool blown = false;
        for (int i = 0; i < n; i++) {
            int consumption;
            cin >> consumption;
            devices.push_back(make_pair(consumption, false));
        }
        int max = INT_MIN;
        int power = 0;
        for (int i = 0; i < m; i++) {
            int device;
            cin >> device;
            if (devices[device - 1].second == false) {
                devices[device - 1].second = true;
                power += devices[device - 1].first;
            }
            else {
                devices[device - 1].second = false;
                power -= devices[device - 1].first;
            }
            max = MAX(max,power);
            if (max > c) {
                blown = true;
            }
        }
        cout << "Sequence " << j++ << endl;
        if (blown) {
            cout << "Fuse was blown." << endl;
        }
        else {
            cout << "Fuse was not blown." << endl << "Maximal power consumption was " << max << " amperes." << endl;
        }
        cout << endl;
        cin >> n >> m >> c;
    }
    return 0;
}
