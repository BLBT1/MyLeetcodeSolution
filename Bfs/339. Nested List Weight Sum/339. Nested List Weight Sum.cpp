/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
public:
    int depthSum(vector<NestedInteger> &nestedList)
    {
        // need to know the depth of each integer.
        // thinking like a tree, do level order traversal
        queue<pair<NestedInteger, int>> q;
        int depth = 1;
        for (auto ni : nestedList)
        {
            q.push({ni, depth});
        }

        int res = 0;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            NestedInteger curr_ni = curr.first;
            int curr_depth = curr.second;
            if (curr_ni.isInteger())
            {
                res += curr_depth * curr_ni.getInteger();
            }
            else
            {
                for (auto next : curr_ni.getList())
                {
                    q.push({next, curr_depth + 1});
                }
            }
        }

        return res;
    }
};