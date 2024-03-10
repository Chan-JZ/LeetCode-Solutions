#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ret;
    vector<string> dict;
    void recursion(string s, int left, int n, string cur) {
        if (left >= n) return;

        int right = left;
        while (right < n && left < n) {
            string window = s.substr(left, right-left+1);
            if (find(dict.begin(), dict.end(), window) == dict.end()) {
                right++;
                window = s.substr(left, right-left+1);
            } else {
                if (right == n-1) {
                    cur.append(window);
                    ret.push_back(cur);
                    return;
                }
                string temp = window + " ";
                int curLen = cur.length();
                cur.append(temp);
                recursion(s, right+1, n, cur);
                cur.erase(curLen, temp.length());
                ++right;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ret.clear();
        dict = wordDict;
        string cur;

        recursion(s, 0, s.length(), cur);

        return ret;
    }
};