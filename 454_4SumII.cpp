#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        int count = 0;

        for (int x : nums1) {
            for (int y : nums2) {
                m[x + y]++;
            }
        }

        for (int x : nums3) {
            for (int y : nums4) {
                if (m[-(x + y)] != 0) count += m[-(x + y)];
            }
        }

        return count; 
    }
};