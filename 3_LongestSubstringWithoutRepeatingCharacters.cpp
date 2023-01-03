#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int slow = 0;
        int ret = INT32_MIN;
        int curLen = 0;

        for (int i=0; i<s.length(); i++) {
            if (m[s[i]] != 0) {
                while (s[slow] != s[i]) {
                    cout << "i: " << i << ", " << s[slow] << endl;
                    m[s[slow++]] = 0;
                }
                curLen = i - slow++;
            } else {
                m[s[i]]++;
                curLen++;
                ret = (curLen > ret) ? curLen : ret;
            }
        }

        return (ret == INT32_MIN) ? 0 : ret;
    }
};