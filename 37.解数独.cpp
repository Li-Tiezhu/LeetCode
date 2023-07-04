/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> line = vector<vector<int>>(10, vector<int>(10, 0));
    vector<vector<int>> column = vector<vector<int>>(10, vector<int>(10, 0));
    vector<vector<vector<int>>> square = vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(10, 0)));

    bool backtracking(vector<vector<char>> &board, int curLine, int curColumn) {
        if (curLine == 9) {
            return true;
        }

        bool ret = false;
        for (int i = 1; i <= 9; i++) {
            if (line[curLine][i] == 1 || column[curColumn][i] == 1 || square[curLine/3][curColumn/3][i] == 1) {
                continue;
            }
            if (board[curLine][curColumn] != '.') {
                continue;
            }
            square[curLine/3][curColumn/3][i] = 1;
            line[curLine][i] = 1;
            column[curColumn][i] = 1;
            board[curLine][curColumn] = i + '0';
            if (curColumn + 1 == 9) {
                ret = backtracking(board, curLine + 1, 0);
            }
            else {
                ret = backtracking(board, curLine, curColumn + 1);
            }
            if (ret == true) {
                return true;
            }
            square[curLine/3][curColumn/3][i] = 0;
            line[curLine][i] = 0;
            column[curColumn][i] = 0;
            board[curLine][curColumn] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    line[i][board[i][j] - '0'] = 1;
                    column[j][board[i][j] - '0'] = 1;
                    square[i/3][j/3][board[i][j] - '0'] = 1;
                }
            }
        }
        backtracking(board, 0, 0);
    }
};
// @lc code=end
