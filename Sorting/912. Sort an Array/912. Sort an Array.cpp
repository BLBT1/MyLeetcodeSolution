class Solution
{
    int temp[50000]; // for mergesort
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    // 用这个题目归纳一下quick sort和 merge sort的模板
    void quickSort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        int p = nums[l + (r - l) / 2];
        int i = l - 1, j = r + 1;
        while (i < j)
        {
            do
                ++i;
            while (nums[i] < p);
            do
                --j;
            while (nums[j] > p);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        quickSort(nums, l, j);
        quickSort(nums, j + 1, r);
    }

    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1, k = 0; // k point to temp

        // merge two sorted part
        while (i <= mid && j <= r)
        {
            if (nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= r)
            temp[k++] = nums[j++];

        // copy back to nums[l:r]
        for (int pos = l, k = 0; pos <= r; ++pos, ++k)
            nums[pos] = temp[k];
    }
};