#include <iostream>
#include <vector>
using namespace std;

int main() {
    double duration;
    cin >> duration;
    while (duration > 0) {
        double down, loan;
        int n;
        cin >> down >> loan >> n;
        double value = down + loan;
        double monthlyPayment = loan / duration;
        vector <double> dep (101, -1);
        for (int i = 0; i < n; i++) {
            int month;
            double percentage;
            cin >> month >> percentage;
            dep[month] = percentage;
        }
        for (int i = 1; i <= duration; i++) {
            if (dep[i] == -1) {
                dep[i] = dep[i-1];
            }
        }
        int currentMonth = 0;
        value = value - (value * dep[0]);
        while (value < loan) {
            loan -= monthlyPayment;
            value = value - (value * dep[++currentMonth]);
        }
        if (currentMonth == 1) {
            cout << currentMonth << " month" << endl;
        }
        else {
            cout << currentMonth << " months" << endl;
        }
        cin >> duration;
    }
    return 0;
}
