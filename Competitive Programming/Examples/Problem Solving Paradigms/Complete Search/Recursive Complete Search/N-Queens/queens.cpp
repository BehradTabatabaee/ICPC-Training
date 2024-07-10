#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<string>> ans;

bool isSolved(vector<string>& board) {
    for (auto i : board) {
        if (i.find('Q') == string::npos) {
            return false;
        }
    }
    return true;
}

bool columnContainsQueen(vector<string>& board, int i, int j) {
    for (int k = i; k >= 0; k--) {
        if (board[k][j] == 'Q') return true;
    }
    return false;
}

bool diagonalContainsQueen(vector<string>& board, int i, int j) {
    int tempI = i, tempJ = j;
    while (i >= 0 && j >= 0) {
        if (board[i--][j--] == 'Q') return true;
    }

    i = tempI;
    j = tempJ;

    while (i >= 0 && j < board.size()) {
        if (board[i--][j++] == 'Q') return true;
    }

    return false;
}


void solveNQueens(vector<string>& board, int row = 0) {
    if (row == board.size()) {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < board.size(); col++) {
        if (!columnContainsQueen(board, row, col) && !diagonalContainsQueen(board, row, col)) {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n;
    string temp = "";
    for (int i = 0; i < n; i++) {
        temp += ".";
    }
    vector<string> board(n, temp);
    solveNQueens(board);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}