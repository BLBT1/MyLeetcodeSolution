/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
private:
    stack<NestedInteger> s;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        //* push all NestedInteteger from the list into the stack
        //* in reversed order
        for (int i = nestedList.size() - 1; i >= 0; --i)
            s.push(nestedList[i]);
    }

    int next()
    {
        // now the top must be int after hasNext() called
        int val = s.top().getInteger();
        s.pop();
        return val;
    }

    bool hasNext()
    {
        while (!s.empty() && !s.top().isInteger())
        {
            auto data = s.top().getList();
            s.pop();
            for (int i = data.size() - 1; i >= 0; --i)
            {
                s.push(data[i]);
            } //for
        }     //while

        // now the top must be int
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
