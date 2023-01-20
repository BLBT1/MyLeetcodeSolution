/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution
{
public:
    int getIndex(ArrayReader &reader)
    {
        int l = 0;
        int r = reader.length() - 1;
        int mid;
        while (l < r)
        {
            int compare;
            mid = l + (r - l) / 2;
            if (mid - l + 1 > r - mid)
            {
                mid = mid - 1;
                compare = reader.compareSub(l, mid, mid + 2, r);
            }
            else
            {
                compare = reader.compareSub(l, mid, mid + 1, r);
            }
            if (compare == 0)
            {
                return mid + 1;
            }
            else if (compare == -1)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};

//  0 1 2 3 4 5 6 7 8
// [2,1,1,1,1,1,1,1,1]
//  l
//  r
//  m