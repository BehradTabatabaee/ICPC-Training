#include <iostream>
#include <string>
using namespace std;

int sumOfDigits(long long a) {
    if (a < 10 && a > 0) {
        return a;
    }
    string str = to_string(a);
    long long sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += str[i] - '0';
    }
    return sumOfDigits(sum);
}

int main() {
    long long a;
    cin >> a;
    while (a != 0) {
        cout << sumOfDigits(a) << endl;
        cin >> a;
    }
    return 0;
}