#include <iostream>
#include <deque>
#include <math.h>
#include <string>
using namespace std;

#define snp random()/141%2

void snap(string name, deque<char>& top) {
    cout << "Snap! for " << name << ": ";
    deque<char> temp;

    while (!top.empty()) {
        temp.push_back(top.back());
        cout << top.back();
        top.pop_back();
    }
    cout << endl;
    while (!temp.empty()) {
        top.push_back(temp.back());
        temp.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    for (int tc = 0; tc < n; tc++) {
        if (tc != 0)
            cout << endl;
        deque<char> janeTop, johnTop;
        deque<char> janeDown, johnDown;
        string jane, john;
        cin >> jane >> john;
        int size = jane.size();
        for (int i = 0; i < size; i++) {
            janeDown.push_back(jane[i]);
            johnDown.push_back(john[i]);
        }
        int count = 0;
        while ((!janeTop.empty() || !janeDown.empty()) && (!johnTop.empty() || !johnDown.empty())) {
            if (count >= 1000) {
                cout << "Keeps going and going ..." << endl;
                goto end;
            }
            if (johnDown.empty()) {
                while (!johnTop.empty()) {
                    johnDown.push_back(johnTop.front());
                    johnTop.pop_front();
                }
            }
            if (janeDown.empty()) {
                while (!janeTop.empty()) {
                    janeDown.push_back(janeTop.front());
                    janeTop.pop_front();
                }
            }
            janeTop.push_back(janeDown.front());
            janeDown.pop_front();
            johnTop.push_back(johnDown.front());
            johnDown.pop_front();
            if (janeTop.back() != johnTop.back()) continue;
            if (snp == 0) {
                while (!johnTop.empty()) {
                    janeTop.push_back(johnTop.front());
                    johnTop.pop_front();
                }
                snap("Jane", janeTop);
            }
            else {
                while (!janeTop.empty()) {
                    johnTop.push_back(janeTop.front());
                    janeTop.pop_front();
                }
                snap("John", johnTop);
            }
            count++;
        }
        if ((!janeTop.empty() || !janeDown.empty())) {
            cout << "Jane wins." << endl;
        }
        else {
            cout << "John wins." << endl;
        }
        end:
        continue;
    }
    return 0;
}