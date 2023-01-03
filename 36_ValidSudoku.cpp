#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));
        vector<vector<int>> blocks(9, vector<int>(9, 0));

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                int nums = board[i][j] - '0' - 1;
                int k = (i/3)*3 + (j/3);
                
                if (board[i][j] != '.') {
                    if (rows[i][nums] || cols[nums][j] || blocks[k][nums]) return false;
                    rows[i][nums] = cols[nums][j] = blocks[k][nums] = 1;
                }

            }
        }

        return true;
    }
};