#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int main() {
    int n,p;
    cin >> n >> p;
    cin.ignore();
    int RFP = 1;
    while (n != 0 || p != 0) {
        for (int i = 0; i < n; i++) {
            string uselessRequirements;
            getline(cin,uselessRequirements);
        }
        vector <pair<string,pair<double,double>>> requests;
        for (int i = 0; i < p; i++) {
            string name;
            getline(cin,name);
            double price, number;
            cin >> price >> number;
            cin.ignore();
            requests.push_back(make_pair(name,make_pair(price, number / n)));
            for (int j = 0; j < number; j++) {
                string useless;
                getline(cin,useless);
            }
        }
        vector <pair<string,pair<double,double>>> highestComp;
        double max = INT_MIN;
        for (int i = 0; i < requests.size(); i++) {
            if (requests[i].second.second >= max) {
                max = requests[i].second.second;
            }
        }
        for (int i = 0; i < requests.size(); i++) {
            if (requests[i].second.second == max) {
                highestComp.push_back(requests[i]);
            }
        }
        cout << "RFP #" << RFP << endl; 
        if (highestComp.size() == 1) {
            cout << highestComp[0].first << endl;
        }
        else {
            int minPrice = INT_MAX;
            for (int i = 0; i < highestComp.size(); i++) {
                if (highestComp[i].second.first <= minPrice) {
                    minPrice = highestComp[i].second.first;
                }
            }
            for (int i = 0; i < highestComp.size(); i++) {
                if (highestComp[i].second.first == minPrice) {
                    cout << highestComp[i].first << endl;
                    break;
                }
            }
        }
        cin >> n >> p;
        cin.ignore();
        RFP++;
        if (n != 0 || p != 0) {
            cout << endl;
        }
    }
    return 0;
}