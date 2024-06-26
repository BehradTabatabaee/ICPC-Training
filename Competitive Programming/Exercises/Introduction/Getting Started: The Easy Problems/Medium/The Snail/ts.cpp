#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double h,u,d,f;
    cin >> h >> u >> d >> f;
    while (h != 0) {
        double current = 0, day = 1;
        double fatigue = (f / 100) * u;
        while (true) {
            if (u > 0) {
                current += u;
            }
            if (current > h) {
                cout << "success on day " << day << endl;
                break;
            }
            current -= d;
            if (current < 0) {
                cout << "failure on day " << day << endl;
                break;
            }
            u -= fatigue;
            day++;
        }
        cin >> h >> u >> d >> f;
    }
    return 0;
}
