#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int n = s.length();
        int index = n-1;

        while(index >= 0) {
            while(index >= 0 && s[index] == ' ') index--;

            int start = index;
            while(index >= 0 && s[index] != ' ') index--;

            if (index >= -1 && s[index+1] != ' ') {
                string curWord = s.substr(index+1, start-index);
                ret += curWord + " ";
            }     
        }

        ret.pop_back();
        return ret;
    }
};
