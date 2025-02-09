#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        int maxF = 0, f = 0;

        for (int x : nums) {
            freq[x]++;
            f += (freq[x] == maxF);
            
            if (freq[x] > maxF) maxF = freq[x], f = 1;
        }

        return f * maxF;
    }
};