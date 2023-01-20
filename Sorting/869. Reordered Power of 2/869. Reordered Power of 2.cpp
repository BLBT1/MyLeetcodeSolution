class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        // 把可能的2的平方和n都排序一下来对比
        string s = to_string(n);
        sort(s.begin(), s.end());
        long num = 1;
        for (int i = 0; i < 32; ++i)
        {
            string s_ = to_string(num);
            sort(s_.begin(), s_.end());
            if (s_ == s)
                return true;
            num = num << 1;
        }

        return false;
    }
};