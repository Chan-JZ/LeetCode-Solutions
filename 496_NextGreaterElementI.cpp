#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> s;

        for (int x : nums2) {
            int cur = x;
            
            while(!s.empty() && cur > s.top()) {
                int temp = s.top();
                s.pop();
                mp[temp] = cur;
            }
            s.push(cur);
        }

        for (int &x : nums1) {
            if (mp.find(x) != mp.end()) x = mp[x];
            else x = -1;
        }

        return nums1;
    }
};