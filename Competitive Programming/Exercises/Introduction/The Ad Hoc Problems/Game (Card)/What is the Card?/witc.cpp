#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int tc = 1; tc <= n; tc++) {
        stack<string> cards;
        stack<string> st;
        for (int i = 0; i < 52; i++) {
            string card;
            cin >> card;
            if (i >= 27)   
                st.push(card);
            else
                cards.push(card);
        }
        int y = 0;
        for (int i = 0; i < 3; i++) {
            string card = cards.top();
            cards.pop();
            int x = card[0] - '0';
            if (x >= 2 && x <= 9) {
                y += x;
            }  
            else {
                y += 10;
                x = 10;
            }
            for (int j = 0; j < 10 - x; j++) {
                cards.pop();
            }
        }
        stack <string> newSt;
        while (!st.empty()) {
            newSt.push(st.top());
            st.pop();
        }
        while (!cards.empty()) {
            newSt.push(cards.top());
            cards.pop();
        }
        for (int i = 0; i < y - 1; i++) {
            newSt.pop();
        }
        cout << "Case " << tc << ": " << newSt.top() << endl;
    }
    return 0;
}