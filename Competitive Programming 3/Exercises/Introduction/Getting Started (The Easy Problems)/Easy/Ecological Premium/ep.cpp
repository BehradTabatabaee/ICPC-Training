#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        double sum = 0;
        for (int j = 0; j < num; j++) {
            double a,b,c;
            cin >> a >> b >> c;
            sum += ((a / b) * c) * b;
        }
        cout << sum << endl;
    }
    return 0; 
}