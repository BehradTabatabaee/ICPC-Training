#include <iostream>
#include <string>
using namespace std;

#define forr(i, a, b) for(int i = a; i < b; i++)

int main() {
    int l;
    while (cin >> l) {
        if (l == 0)
            break;
        string p = "+x";
        forr(i, 0, l-1) {
            string b = "";
            cin >> b;
            if (b == "No") continue;
            if (p == "+x") {
                p = b;
            } else if (p == "-x") {
                p = ((b[0] == '+')? "-" : "+");
                p += b[1];
            } else if (p == "+y") {
                if (b[1] == 'z') {
                    p = p;
                } else if (b[0] == '-') {
                    p = "+x";
                } else {
                    p = "-x";
                }
            } else if (p == "-y") {
                if (b[1] == 'z') {
                    p = p;
                } else {
                    p = b[0];
                    p += "x";
                }
            } else if (p == "+z") {
                if (b[1] == 'y') {
                    p = p;
                } else {
                    p = ((b[0] == '+')? "-" : "+");
                    p += "x";
                }
            } else if (p == "-z") {
                if (b[1] == 'y') {
                    p = p;
                } else {
                    p = b[0];
                    p += "x";
                }
            }
        }
        cout << p << endl;
    }

    return 0;
}