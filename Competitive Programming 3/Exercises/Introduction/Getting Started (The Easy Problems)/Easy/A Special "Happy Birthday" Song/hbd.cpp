#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> people; 
    for (int i = 0; i < n; i++) {
        string person;
        cin >> person;
        people.push_back(person);
    }
    bool hasEveryoneSang = false;
    int i = 0, k = 0;
    while (!hasEveryoneSang || i % 16 != 0) {
        if (i % 4 == 0) {
            cout << people[k % people.size()] <<  ": " << "Happy" << endl;
        }
        else if (i % 4 == 1) {
            cout << people[k % people.size()] <<  ": " << "birthday" << endl;
        }
        else if (i % 4 == 2) {
            cout << people[k % people.size()] <<  ": " << "to" << endl;
        }
        else if (i % 4 == 3) {
            if (i % 16 == 11) {
                cout << people[k % people.size()] <<  ": " << "Rujia" << endl;
            }
            else {
                cout << people[k % people.size()] <<  ": " << "you" << endl;
            }
        }
        i++;
        k++;
        if (k >= people.size()) {
            hasEveryoneSang = true;
        }
    }
    return 0;
}
