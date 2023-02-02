/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target,
                            MountainArray &mountainArr)
    {
        // find peak
        int peak = findPeak(mountainArr);
        int idx1 = bsearch1(target, mountainArr, 0, peak);
        if (idx1 != -1)
            return idx1;
        int idx2 = bsearch2(target, mountainArr, peak + 1, mountainArr.length() - 1);
        return idx2;
    }

    int findPeak(MountainArray &ma)
    {
        int l = 1;
        int r = ma.length() - 1;
        while (l < r)
        {
            int mid = (r - l + 1) / 2 + l;
            if (ma.get(mid - 1) < ma.get(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    int bsearch1(int target,
                 MountainArray &ma,
                 int begin, int end)
    {
        int l = begin, r = end;
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (ma.get(mid) < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (l == r && ma.get(l) == target)
            return l;
        else
            return -1;
    }

    int bsearch2(int target,
                 MountainArray &ma,
                 int begin, int end)
    {
        int l = begin;
        int r = end;
        // cout << l <<" " << r << endl;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (ma.get(mid) <= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (l == r && ma.get(l) == target)
            return l;
        return -1;
    }
};

// 3
// [2, 1]
//  l
//     r
// 3
// [5,3,1]
// first find peak
// then do binary search 2 times

// [1, 5, 2]
//  l
//        r

// [3, 1]
// l
//     r