#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0;
        int n = nums1.size(), m = nums2.size();

        while (i1 < n && i2 < m) {
            if (nums1[i1] == nums2[i2]) return nums1[i1];

            else if (nums1[i1] < nums2[i2]) i1++;

            else i2++;
        }

        return -1;
    }
};

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        for (auto x : nums1) {
            mp[x]++;
        }

        for (auto x : nums2) {
            if (mp[x] > 0) return x;
        }

        return -1;
    }
};

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());

        for (int i=0; i<nums2.size(); i++) {
            if (s.count(nums2[i])) return nums2[i];
        }

        return -1;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return true;

            else if (nums[mid] > target) r = mid - 1;

            else l = mid + 1;
        }

        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            if (search(nums2, nums1[i])) return nums1[i];
        }

        return -1;
    }
};