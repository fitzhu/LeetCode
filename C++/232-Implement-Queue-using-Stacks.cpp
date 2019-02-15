#include<stack>
using namespace std;

// 用两个栈，栈1存push进来的数，栈2倒序存以前的数（每次peek时把栈1的数拿过来）
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1_.emplace(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto num = peek();
        s2_.pop();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2_.empty()) {
            while (!s1_.empty()) {
                s2_.emplace(s1_.top());
                s1_.pop();
            }
        }
        return s2_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1_.empty() && s2_.empty();
    }
private:
    stack<int> s1_, s2_;
};
