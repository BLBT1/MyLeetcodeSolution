/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack() : curr_min{INT_MAX} {}

    //* store the diff between old min and input val
    void push(int val)
    {
        if (data.empty())
        {
            curr_min = val;
            data.push(0);
        } // if
        else
        {
            data.push(val - curr_min);
            if (val < curr_min)
            {
                curr_min = val;
            } //if
        }     //else
    }

    //* pop need to update the curr min
    void pop()
    {
        if (data.top() <= 0)
        {
            curr_min -= data.top();
        } //if
        data.pop();
    }

    int top()
    {
        if (data.top() >= 0)
        {
            return data.top() + curr_min;
        } //if
        else
        {
            return curr_min;
        } //else
    }

    int getMin()
    {
        return curr_min;
    }

private:
    stack<long> data;
    long curr_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
