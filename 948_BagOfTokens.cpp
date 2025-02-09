#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (!tokens.size()) return 0;

        sort(tokens.begin(), tokens.end());
        int size = tokens.size();
        int score = 0, ret = 0, left = 0, right = size - 1;

        while (left <= right) {
            if (tokens[left] <= power) {
                power -= tokens[left++];
                ret = max(ret, ++score);
            }

            else if (score) {
                power += tokens[right--];
                score--;
            }

            else break;
        }

        return ret;
    }
};