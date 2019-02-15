#include<stack>
using namespace std;

// 栈内存储的是与当前最小值的差值
class MinStack {
public:  
    void push(int x) {
        if (elements_.empty()) {
            elements_.emplace(0);
            stack_min_ = x;
        } else {
            elements_.emplace(static_cast<int64_t>(x) - stack_min_);
            if (x < stack_min_) {
                stack_min_ = x;
            }
        }
    }
    
    void pop() {
        auto diff = elements_.top();
        elements_.pop();
        if (diff < 0) {
            stack_min_ -= diff; // Restore previous min.
        }
    }
    
    int top() {
        if (elements_.top() > 0) {
            return stack_min_ + elements_.top();
        } else {
            return stack_min_;
        }
    }
    
    int getMin() {
        return stack_min_;
    }
private:
    stack<int64_t> elements_;
    int stack_min_;
};