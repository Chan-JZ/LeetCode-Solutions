#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word, visited)) return true;
            }
        }

       return false;
    }

    bool dfs(int i, int j, int len, vector<vector<char>>& board, string word, vector<vector<bool>>& visited) {
        if (len == word.length()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (visited[i][j] || board[i][j] != word[len]) return false;

        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            if (dfs(i+dx[k], j+dy[k], len+1, board, word, visited)) return true;
        }
        visited[i][j] = false;
        
        return false;
    }
};