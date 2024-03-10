#include <iostream>
#include <Vector>

using namespace std;

class MinStack {
public:
    vector<int> stk1;
    vector<int> stk2;
    MinStack() {
        stk1.clear();
        stk2.clear();
    }
    
    void push(int val) {
        stk1.push_back(val);
        if (stk2.empty() || val <= getMin()) stk2.push_back(val);
    }
    
    void pop() {
        if (stk1.back() == getMin()) stk2.pop_back();
        stk1.pop_back();
    }
    
    int top() {
        return stk1.back();
    }
    
    int getMin() {
        return stk2.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */