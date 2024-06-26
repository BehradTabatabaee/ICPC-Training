#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        number = ((((((number * 567) / 9) + 7492) * 235) / 47) - 498);
        string numstr = to_string(number);
        cout << numstr[numstr.size() - 2] << endl;
    }
    return 0;
}