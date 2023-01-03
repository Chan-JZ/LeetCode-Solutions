#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        unordered_map<int, vector<char>> m = {
            {2, vector<char> {'a', 'b', 'c'}},
            {3, vector<char> {'d', 'e', 'f'}},
            {4, vector<char> {'g', 'h', 'i'}},
            {5, vector<char> {'j', 'k', 'l'}},
            {6, vector<char> {'m', 'n', 'o'}},
            {7, vector<char> {'p', 'q', 'r', 's'}},
            {8, vector<char> {'t', 'u', 'v'}},
            {9, vector<char> {'w', 'x', 'y', 'z'}},
        };

        dfs(digits, "", 0, ret, m);

        return ret;
    }

    void dfs(string s, string cur, int len, vector<string>& ret, unordered_map<int,     vector<char>>& m) {
        if (len == s.size() && len != 0) {
            ret.push_back(cur);
            return;
        }

        int curNum = s[len] - '0';
        for (int i=0; i<m[curNum].size(); i++) {
            cur += m[curNum][i];
            dfs(s, cur, len+1, ret, m);
            cur.pop_back();
        }
    }
};