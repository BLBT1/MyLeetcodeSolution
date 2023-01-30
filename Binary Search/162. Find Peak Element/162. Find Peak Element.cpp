class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int l = 0;
        int r = nums.size();
        int mid;
        while (l < r)
        {
            int mid = (r - l + 1) / 2 + l;

            if (mid == 0)
                l = mid;
            else if (mid == nums.size())
                r = mid - 1;
            else if (nums[mid] > nums[mid - 1])
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

// if(nums[mid] > nums[mid-1])
//     l = mid
// else
//     r = mid - 1;

//     m
// 1,2,3,1
// l     r
