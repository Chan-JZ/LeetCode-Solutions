#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k) {
        for (int i=0; i<s.length(); i+=k*2) {
            int end;
            if (s.length()-i >= k) end = i+k;
            else end = s.length();

            reverse(s, i, end-1);
        }
        
        return s;
    }
};