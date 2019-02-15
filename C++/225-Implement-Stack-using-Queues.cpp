#include<queue>
using namespace std;

// 注意两种数据集结构的不一致，queue为先进后出，stack为后进先出
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {      // O(n)
        q_.emplace(x);
        for (int i = 0; i < q_.size() - 1; ++i) {
            q_.emplace(q_.front());
            q_.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto num = q_.front();
        q_.pop();
        return num;
    }
    
    /** Get the top element. */
    int top() {
        return q_.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q_.empty();
    }
private:
    queue<int> q_;
};