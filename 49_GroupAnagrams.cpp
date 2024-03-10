#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<vector<int>, vector<string>> m;

        for (string s : strs) {
            vector<int> charCount(26, 0);
            for (char c : s) {
                charCount[c - 'a']++;
            }

            if (m.find(charCount) != m.end()) m[charCount].push_back(s);
            else m[charCount] = vector<string> {s};
        }

        for (auto it=m.begin(); it != m.end(); it++) ret.push_back(it->second);

        return ret;
    }
};