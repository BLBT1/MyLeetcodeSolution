class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int i = 0, j = 0;
        for (; j < nums.size(); ++j)
        {
            if (nums[j] == 0)
            {
                if (i >= nums.size())
                    return res;
                else
                    i = j + 1;
            }
            res = max(j - i + 1, res);
        }
        return res;
    }
};

//
//
// res = 2
// [1,0,1,1,0,1]
//  i
//       j