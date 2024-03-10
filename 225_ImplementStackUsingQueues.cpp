#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        n--;

        while(n--) {
            q2.push(q1.front());
            q1.pop();
        }

        int ret = q1.front();
        q1.pop();
        
        q1 = q2;
        while(!q2.empty()) {
            q2.pop();
        }

        return ret;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */