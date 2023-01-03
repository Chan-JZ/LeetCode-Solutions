#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = nums.size()-1;
        vector<int> result(nums.size(), 0);

        for (int i=0, j=nums.size()-1; i<=j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                result[index--] = nums[i] * nums[i];
                i++;
            } else {
                result[index--] = nums[j] * nums[j];
                j--;
            }
        }

        return result;
    }
};