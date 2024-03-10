#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        int ret = out.top();
        out.pop();
        return ret;
    }
    
    int peek() {
        int ret = this->pop();
        out.push(ret);
        return ret;
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */