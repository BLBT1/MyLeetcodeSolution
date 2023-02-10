class Solution
{
public:
    long long kthSmallestProduct(vector<int> &nums1,
                                 vector<int> &nums2,
                                 long long k)
    {
        long long low = -1e10;
        long long hi = 1e10;
        while (low < hi)
        {
            long long mid = low + (hi - low) / 2;
            if (cntSmallerEqual(nums1, nums2, mid) < k)
                low = mid + 1;
            else
                hi = mid;
        }
        return low;
    }

    long long cntSmallerEqual(vector<int> &nums1,
                              vector<int> &nums2,
                              long long val)
    {
        int m = nums1.size();
        int n = nums2.size();
        long long cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            if (nums1[i] > 0)
            {
                int j = upper_bound(nums2.begin(), nums2.end(), floor(val * 1.0 / nums1[i])) - 1 - nums2.begin();
                cnt += j - 0 + 1;
            }
            else if (nums1[i] < 0)
            {
                int j = lower_bound(nums2.begin(), nums2.end(), ceil(val * 1.0 / nums1[i])) - nums2.begin();
                cnt += n - 1 - j + 1;
            }
            else
            {
                if (val >= 0)
                    cnt += n;
            }
        }
        return cnt;
    }
};
// 55
// -9.xxx
// -10
// [-6]
// [-9]
// 1
// difficulty of this problem is how to cnt Smaller equal of val

// nums1[i] * nums2[j] <= val
// 因为 nums2 是 monotonic increasing的
// 我们遍历 nums1，同样递增的nums2，我们可以用binary search找一个j的零界点
// 这里有正负符号的问题，所以我们要对不等式进行分类讨论
// 1. nums1[i] > 0, then nums2[j] <= val/nums1[i] [0, j]
//     we need to find a upper bound of j, as nums2 is monotonic increasing
//     3*3 <= 10 => nums2[1,2,3, 4,5...], upper_bound(floor(10/3)) gives us 4, so we take floor()
//     j = upper_bound(nums2.beign(), nums2.end(), floor(val*1.0/nums1[i]))-1-nums2.begin();
// 2. nums1[i] < 0, then nums2[i] >= val/nums1[i]
//     we need to find a lower bound of j, [j, n-1]
//     -3*nums2[j] <= -10 -> nums2[j] >= -10/-3 => 3.333...
//     need to find first elemet in nums2 such ceil(val*1.0/nums1[i])
//     j = lower_bound(nums2.begin(), nums2.end(),ceil(val*1.0/nums1[i]))-nums2.begin();
// 3. nums1[i] == 0
//     if val >= 0, nums2.size()
//     else 0
