#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define fori(n) for (int i = 0; i < n; i++)
#define ll long long

string fix(string& str) {
    string res = "";
    int len = str.length();
    fori(len) {
        if (isalpha(str[i])) {
            res += tolower(str[i]);
        }
    }
    return res;
}

int sumOfDigits(long long a) {
    if (a < 10 && a > 0) {
        return a;
    }
    string str = to_string(a);
    long long sum = 0;
    int len = str.length();
    fori(len) {
        sum += str[i] - '0';
    }
    return sumOfDigits(sum);
}

int main() {
    string str1, str2;
    while (getline(cin, str1) && getline(cin, str2)) {
        str1 = fix(str1);
        str2 = fix(str2);
        ll n1 = 0, n2 = 0;
        int len1 = str1.length(), len2 = str2.length();
        fori(len1) {
            n1 += (str1[i] + 1) - 'a';
        }
        fori(len2) {
            n2 += (str2[i] + 1) - 'a';
        }
        int sn1 = sumOfDigits(n1), sn2 = sumOfDigits(n2);
        cout << fixed << setprecision(2) << double(min(sn1, sn2)) / max(sn1, sn2) * 100 << " %" << endl;
    }
    return 0;
}
