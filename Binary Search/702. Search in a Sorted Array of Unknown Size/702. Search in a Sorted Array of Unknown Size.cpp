/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution
{
public:
    int search(const ArrayReader &reader, int target)
    {
        int left = 0, right = 1e4;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (reader.get(mid) > target || reader.get(mid) == INT_MAX - 1)
            {
                // out out bound
                right = mid - 1;
            }
            else if (reader.get(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        if (left == right && reader.get(left) == target)
            return left;
        else
            return -1;
    }
};
