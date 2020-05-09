/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:

    Methods pop, top and getMin operations will always be called on non-empty stacks.*/

#include<stack>
class MinStack {
    stack< long long int> s;
    long long int minEle;
public:
    /** initialize your data structure here. */
    MinStack() {
        minEle=INT_MAX;
    }
    
    void push(long long int x) {
       if(s.empty())
       {
           minEle=x;
           s.push(x);
           return;
       }
        if(x>minEle)
        {
            s.push(x);
            return;
        }
        else
        {
            //s.push(2*x-minEle);
            s.push(x-minEle+x);
            minEle=x;
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        long long int t=s.top();
        s.pop();
        if(t<minEle)
            minEle=2*minEle-t;
    }
    
    int top() {
        long long int t=s.top();
        if(t<minEle)
            return minEle;
        else
            return t;
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

