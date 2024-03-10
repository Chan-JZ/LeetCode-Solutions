#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ret;
        int count = 0, rank = 0;

        for (int x : nums) {
            count += (x == target);
            rank += (x < target);
        }

        while(count--) {
            ret.push_back(rank++);
        }

        return ret;
    }
};