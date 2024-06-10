#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<int> &v)
{
    size_t n = v.size() / 2;
    nth_element(v.begin(), v.begin() + n, v.end());
    return v[n];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector <int> salaries;
        for (int j = 0; j < 3; j++) {
            int salary;
            cin >> salary;
            salaries.push_back(salary);
        }
        cout << "Case " << i + 1 << ": " << median(salaries) << endl;
    }
    return 0;
}
