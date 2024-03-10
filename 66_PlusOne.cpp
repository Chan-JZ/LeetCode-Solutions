#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size()-1;
        digits[index] += 1;
        while(digits[index] == 10) {
            if (index == 0) {
                digits.insert(digits.begin(), 1);
                digits[index+1] = 0;
            } else {
                digits[index] = 0;
                digits[index-1] += 1;
                index--;
            }
        }

        return digits;
    }
};