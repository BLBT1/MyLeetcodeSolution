class Solution
{
public:
    int totalFruit(vector<int> &nums)
    {
        int n = nums.size();
        int elt1 = -1, elt2 = -1;
        int pos1, pos2; // update to the last appear of elt1 and elt2
        int res = 0;
        int i = 0;
        int j = 0;
        for (; j < n; ++j)
        {
            if (elt1 == -1)
            {
                elt1 = nums[j];
                pos1 = j;
            }
            else if (nums[j] != elt1 && elt2 == -1)
            {
                elt2 = nums[j];
                pos2 = j;
            }
            else
            {
                if (elt1 == nums[j])
                {
                    pos1 = j;
                }
                else if (elt2 == nums[j])
                {
                    pos2 = j;
                }
                else
                {
                    // choose one with smaller pos to evict
                    if (pos1 < pos2)
                    {
                        i = pos1 + 1;
                        elt1 = nums[j];
                        pos1 = j;
                    }
                    else
                    {
                        i = pos2 + 1;
                        elt2 = nums[j];
                        pos2 = j;
                    }
                }
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};