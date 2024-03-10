#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    class MyQueue {
    public:
        deque<int> q;

        void pop(int x) {
            if (!q.empty() && q.front() == x) q.pop_front();
        }

        void push(int x) {
            while (!q.empty() && x > q.back()) q.pop_back();
            q.push_back(x);
        }

        int front() {return q.front();}
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        MyQueue q;

        for (int i=0; i<k; i++) {
            q.push(nums[i]);
        }
        ret.push_back(q.front());

        for (int i=k; i<nums.size(); i++) {
            q.pop(nums[i-k]);
            q.push(nums[i]);
            ret.push_back(q.front());
        }

        return ret;
    }
};