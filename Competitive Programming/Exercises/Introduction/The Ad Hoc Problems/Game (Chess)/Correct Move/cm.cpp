#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kingMoves(int king, int queen) {
    vector<int> kingLegal;
    if ((king / 8) != 7) {
        if (king + 8 != queen)
            kingLegal.push_back(king + 8);
    }
    if ((king % 8) != 7) {
        if (king + 1 != queen)
            kingLegal.push_back(king + 1);
    }
    if (king > 7) {
        if (king - 8 != queen)
            kingLegal.push_back(king - 8);
    }
    if ((king % 8) != 0) {
        if (king - 1 != queen)
            kingLegal.push_back(king - 1);
    }
    return kingLegal;
}

vector<int> queenMoves(int queen, int king) {
    vector<int> queenLegal;
    int i = (((int)(queen / 8)) * 8) + 7;
    int maxJ = (queen - (i - 7)) + 56;
    int minJ = maxJ % 8;
    int temp = queen;
    while (temp != king && temp >= minJ) {
        if (find(queenLegal.begin(), queenLegal.end(), temp) == queenLegal.end() && temp != queen)
            queenLegal.push_back(temp);
        temp -= 8;
    }
    temp = queen;
    while (temp != king && temp <= maxJ) {
        if (find(queenLegal.begin(), queenLegal.end(), temp) == queenLegal.end() && temp != queen)
            queenLegal.push_back(temp);
        temp += 8;
    }
    int minI = ((int)(queen / 8) * 8);
    int maxI = minI + 8;
    temp = queen;
    while (temp != king && temp < maxI) {
        if (find(queenLegal.begin(), queenLegal.end(), temp) == queenLegal.end() && temp != queen)
            queenLegal.push_back(temp);
        temp += 1;
    }
    temp = queen;
    while (temp != king && temp >= minI) {
        if (find(queenLegal.begin(), queenLegal.end(), temp) == queenLegal.end() && temp != queen)
            queenLegal.push_back(temp);
        temp -= 1;
    }
    return queenLegal;
}

int main() {
    int king, queen, queenTo;
    while (cin >> king >> queen >> queenTo) {
        if (queen == king) {
            cout << "Illegal state" << endl;
            continue;
        }
        vector<int> kingLegal = kingMoves(king, queen);
        vector<int> queenLegal = queenMoves(queen, king);
        if (find(queenLegal.begin(), queenLegal.end(), queenTo) == queenLegal.end()) {
            cout << "Illegal move" << endl;
            continue;
        }
        else {
            if (find(kingLegal.begin(), kingLegal.end(), queenTo) != kingLegal.end()) {
                cout << "Move not allowed" << endl;
                continue;
            }
            vector<int> queenLegal2 = queenMoves(queenTo, king);
            bool canDoAllowed = false;
            for_each(kingLegal.begin(), kingLegal.end(), [&](int& n) {
                if (find(queenLegal2.begin(), queenLegal2.end(), n) == queenLegal2.end()) {
                    canDoAllowed = true;
                }
                });
            if (canDoAllowed) {
                cout << "Continue" << endl;
                continue;
            }
            else {
                cout << "Stop" << endl;
                continue;
            }
        }
    }
    return 0;
}