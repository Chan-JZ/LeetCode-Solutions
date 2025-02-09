#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int p1 = 0, p2 = 0;

        while (i < word1.size() && j < word2.size()) {
            if (word1[i][p1++] != word2[j][p2++]) return false;

            if (p1 >= word1[i].size()) p1 = 0, i++;

            if (p2 >= word2[j].size()) p2 = 0, j++;
        }

        return i == word1.size() && j == word2.size();
    }
};