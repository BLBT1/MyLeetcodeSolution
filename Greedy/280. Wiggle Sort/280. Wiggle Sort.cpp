class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        // even pos need to be smaller then prev
        // odd pos need to be greater then prev
        for (int i = 1; i < nums.size(); ++i)
        {
            if (i % 2 == 0)
            {
                if (nums[i] > nums[i - 1])
                    swap(nums[i], nums[i - 1]);
            }
            else
            {
                if (nums[i] < nums[i - 1])
                    swap(nums[i], nums[i - 1]);
            }
        }
    }
};

// even pos need to be smaller then prev
// odd pos need to be greater then prev

// 这道题的核心是要思考这样直接换会不会破坏之前的顺序， 实际上是不会的
//  0 1 2 3 4 5
// [3,5,2,1,6,4]
//        i
// 这里2和1交换会不会， 也就是i和i-1交换，会不会 i > i-2?
// 其实是不会的，因为之前保证了 nums[i-2] > nums[i-1]
// 这里交换的唯一条件是i是odd且 nums[i] < nums[i-1]
// so nums[i-2] > nums[i-1] > nums[i]
// 所以交换后，nums[i] 仍 < nums[i-2], 不会破坏之前的顺序
// 反之同理