#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;

        int ret = -1;

        int left = 0;
        while (left+needle.length()-1 < haystack.length()) {
            string str = haystack.substr(left, needle.length());
            if (str == needle) return left;
            left++;
        }

        return ret;
    }
};