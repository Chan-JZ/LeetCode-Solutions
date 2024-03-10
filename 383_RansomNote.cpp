#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        
        for (char c : magazine) m[c]++;

        for (char c : ransomNote) {
            if (m[c] != 0) m[c]--;
            else return false;
        }

        return true;
    }
};