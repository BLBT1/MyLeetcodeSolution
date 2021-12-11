class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        res.reserve(nums1.size());
        stack<int> s;                  // monotonic decreasing stack
        unordered_map<int, int> table; //record the next greater element for all elements in nums2

        for (const int num : nums2)
        {
            if (s.empty())
                s.push(num);
            else if (num <= s.top())
            {
                s.push(num);
            }
            else
            {
                while (!s.empty() && s.top() < num)
                {
                    table[s.top()] = num;
                    s.pop();
                } //while
                s.push(num);
            }
        } // for

        // do all querys in nums
        for (const int x : nums1)
        {
            if (table.find(x) == table.end())
            {
                res.push_back(-1);
            } //if
            else
            {
                res.push_back(table[x]);
            } //else
        }     //for

        return res;
    }
};