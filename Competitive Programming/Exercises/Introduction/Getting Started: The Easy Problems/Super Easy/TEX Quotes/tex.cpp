#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    char ch = '\0';
    int count = 1;
    while ((ch = getchar()) != EOF) {
        if (ch == '\"' && count % 2 == 1) {
            cout << "``";
            count++;
        }
        else if (ch == '\"' && count % 2 == 0) {
            cout << "''";
            count++;
        }
        else {
            cout << ch;
        }
    }
    return 0;
}
