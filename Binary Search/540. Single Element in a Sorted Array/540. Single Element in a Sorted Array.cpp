class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int r = n;
        int l = 0;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (mid % 2 == 0)
            {
                if (mid + 1 == n || nums[mid + 1] != nums[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (mid < n - 1 && nums[mid + 1] == nums[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return nums[l];
    }
};
