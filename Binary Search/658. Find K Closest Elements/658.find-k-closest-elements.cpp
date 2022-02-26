/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // keep a window of size k+1,
        // then must either the left end
        // or the left end of the window is not valid
        // we search the index of the left end of the k-size window
        int lo = 0;
        int hi = arr.size() - k; // because the k size

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;

            // examine a window of k+1 size
            // then either the left end or the right end is not valid
            if (x - arr[mid] > arr[mid + k] - x)
            {
                // this case the left end of window is not a valid left end
                lo = mid + 1;
            }
            else if (x - arr[mid] < arr[mid + k] - x)
            {
                // this case the right end is not a valid end,
                // so the curr mid is not valid left end
                // as the window size is k+1
                // we can just set hi to mid
                hi = mid;
            }
            else
            {
                // if eq
                // then by the problem
                // same as the right end is not valid
                hi = mid;
            }
        } // while
        // when out of while loop, must converge
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};
// @lc code=end
