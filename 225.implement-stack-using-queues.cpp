/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack
{
private:
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x)
    {
        //* every time we push
        //* we move all the prev element in the queue to the new element
        //* s.t the queue is in the order from new element to the old

        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        } //for
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    /** Get the top element. */
    int top()
    {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
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
// @lc code=end
