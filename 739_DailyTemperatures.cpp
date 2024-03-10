#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n, 0);
        stack<int> s;

        for (int i=0; i<n; i++) {
            if (!s.empty()) cout << s.top() << endl;
            while (s.size() && temperatures[s.top()] < temperatures[i]) {
                ret[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return ret;
    }
};