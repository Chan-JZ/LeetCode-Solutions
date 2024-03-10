#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int x : nums) {
            if (s.find(x) == s.end()) continue;

            s.erase(x);
            int prev = x - 1;
            int next = x + 1;

            while (s.find(prev) != s.end()) s.erase(prev--);

            while (s.find(next) != s.end()) s.erase(next++);

            ret = max(ret, next-prev-1);
        }

        return ret;
    }
};