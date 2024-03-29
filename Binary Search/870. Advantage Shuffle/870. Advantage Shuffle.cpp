class Solution
{
public:
    vector<int> advantageCount(vector<int> &A,
                               vector<int> &B)
    {
        vector<int> res;
        sort(A.begin(), A.end());
        for (auto b : B)
        {
            int x = findGt(b, A);
            if (x != -1)
            {
                res.push_back(A[x]);
                A.erase(A.begin() + x);
            }
            else
            {
                res.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return res;
    }

    int findGt(int tar, vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0] > tar ? 0 : -1;
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = (r - l) / 2 + l;
            if (nums[mid] <= tar)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if (nums[l] > tar)
            return l;
        return -1;
    }
};