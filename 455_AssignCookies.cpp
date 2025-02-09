#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0, right = 0, ret = 0;

        while (left < g.size() && right < s.size()) {
            if (s[right] >= g[left]) left++, right++, ret++;
            else right++;
        }

        return ret;
    }
};