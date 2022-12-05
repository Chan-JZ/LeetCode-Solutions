#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length()-1;
        while (s[index] == ' ') index--;
        int index2 = 0;
        while (index >= 0 && s[index] != ' ') {
            index--;
            index2++;
        }

        return index2;
    }
};
