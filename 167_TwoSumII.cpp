#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;

        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] < target) {
                left++;
            } else if (numbers[left] + numbers[right] == target) {
                ret = {left+1, right+1};
                return ret;
            } else {
                right--;
            }
        }

        return ret;
    }
};