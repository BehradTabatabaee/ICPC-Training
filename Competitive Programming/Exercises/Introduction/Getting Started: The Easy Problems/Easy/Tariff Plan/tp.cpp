#include <iostream>
using namespace std;

int calcPriceMile(int duration) {
    return (10 + (duration / 30) * 10);
}

int calcPriceJuice(int duration) {
    return (15 + (duration / 60) * 15);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int calls;
        cin >> calls;
        int milePrice = 0, juicePrice = 0;
        for (int j = 0; j < calls; j++) {
            int call;
            cin >> call;
            milePrice += calcPriceMile(call);
            juicePrice += calcPriceJuice(call);
        }
        if (milePrice < juicePrice) {
            cout << "Case " << i + 1 << ": " << "Mile " << milePrice << endl;
        }
        else if (milePrice > juicePrice) {
            cout << "Case " << i + 1 << ": " << "Juice " << juicePrice << endl;
        }
        else {
            cout << "Case " << i + 1 << ": " << "Mile Juice " << juicePrice << endl; 
        } 
    }
    return 0;
}