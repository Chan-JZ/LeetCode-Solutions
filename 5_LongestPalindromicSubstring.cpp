#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        int ret = 1;
        int start = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i=0; i<n; i++) dp[i][i] = true;
        

        for (int i=n-1; i>=0; i--) {
            for (int j=i+1; j<n; j++) {
                if (s[i] == s[j]) {
                    if (j-i > 0 && dp[i+1][j-1] || j-i == 1) {
                        dp[i][j] = true;
                        if (j-i+1 > ret) {
                            ret = j-i+1;
                            start = i;
                        }
                    }
                }
            }
        }
        
        return s.substr(start, ret);

    }
};