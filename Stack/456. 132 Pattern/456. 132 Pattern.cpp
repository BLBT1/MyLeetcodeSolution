class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        // idea: assum each element is the mid (3) element in the pattern
        // 1 3 2, so left < right && left < mid, also mid > right
        // so left must be smallest, find leftMin for all i
        vector<int> leftMin(nums.size(), INT_MAX);
        for (int i = 1; i < nums.size(); ++i)
        {
            leftMin[i] = min(leftMin[i - 1], nums[i - 1]);
        }

        // for each element, find the next greatest element that is smaller then i
        vector<int> nextGtLessThan(nums.size(), INT_MIN);
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && s.top() < nums[i])
            {
                nextGtLessThan[i] = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nextGtLessThan[i] > leftMin[i])
                return true;
        }
        return false;
    }
};

//           |
// |         |
// |         |
// |       | |
// |   |   | |
// | | | | | |

// s decreasing stack
// 6 3 2 1 5 => the last one to be popped in the stack