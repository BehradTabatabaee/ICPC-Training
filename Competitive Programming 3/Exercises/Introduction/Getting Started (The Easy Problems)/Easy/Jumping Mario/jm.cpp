#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int walls;
        cin >> walls;
        vector <int> wls;
        for (int j = 0; j < walls; j++) {
            int wall;
            cin >> wall;
            wls.push_back(wall);
        }
        int high = 0, low = 0;
        for (int j = 1; j < wls.size(); j++) {
            if (wls[j] > wls[j - 1]) {
                high++;
            }
            else if (wls[j] < wls[j - 1]) {
                low++;
            }
        }
        cout << "Case " << i + 1 << ": " << high << " " << low << endl;
    }
    return 0;
}