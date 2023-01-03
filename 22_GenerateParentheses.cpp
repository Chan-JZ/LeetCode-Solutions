#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<string>& ret, string cur, int x, int y, int n) {
        int len = x + y;
        if (len >= n*2) {
            ret.push_back(cur);
            return;
        }

        if (x < n) {
            cur.push_back('(');
            dfs(ret, cur, x+1, y, n);
            cur.pop_back();
        }

        if (y < x) {
            cur.push_back(')');
            dfs(ret, cur, x, y+1, n);
            cur.pop_back();
        }
        
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;

        dfs(ret, "", 0, 0, n);

        return ret;
    }
};