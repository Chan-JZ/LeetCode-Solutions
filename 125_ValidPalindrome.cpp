#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i=0; i<s.length();) {
            if (!isalpha(s[i]) && !isdigit(s[i])) {
                s.erase(i, 1);
                continue;
            }
            else if (isupper(s[i])) s[i] = tolower(s[i]);
            i++;
        }
        cout << s << endl;
        int left = 0, right = s.length()-1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }

        return true;
    }
};