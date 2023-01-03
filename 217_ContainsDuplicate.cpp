#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;

        for (int x : nums) {
            if (m[x] != 0) return true;
            m[x]++;
        }

        return false;
    }
};