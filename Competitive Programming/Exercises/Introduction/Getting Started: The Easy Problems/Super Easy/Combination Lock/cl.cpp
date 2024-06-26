#include <iostream>
#include <math.h>
using namespace std;

float minDegreeClockWise(float s, float e) {
    if ((s - e) > (e - s)) {
        return ((abs(s - e) / 40) * 360);
    } 
    else {
        return (360 - ((abs(s - e) / 40) * 360));
    }
}

float minDegreeCounterClockWise(float s, float e) {
    if ((s - e) < (e - s)) {
        return ((abs(s - e) / 40) * 360);
    } 
    else {
        return (360 - ((abs(s - e) / 40) * 360));
    }
}

int main() {
    float s, c1, c2, c3;
    cin >> s >> c1 >> c2 >> c3;
    while (s || c1 || c2 || c3) {
        cout << 1080 + minDegreeClockWise(s,c1) + minDegreeCounterClockWise(c1, c2) + minDegreeClockWise(c2, c3) << endl;
        cin >> s >> c1 >> c2 >> c3;
    }
    return 0;
}