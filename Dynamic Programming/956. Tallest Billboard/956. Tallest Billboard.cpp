class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size();
        int offset = accumulate(rods.begin(), rods.end(), 0);
        int min_diff = -offset;
        int max_diff = offset;
        vector<int> dp(2 * offset + 1, -1);
        dp[0 + offset] = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = rods[i];
            auto old_dp = dp;
            for (int diff = min_diff; diff <= max_diff; ++diff)
            {
                if (old_dp[diff + offset] == -1)
                    continue;
                if (diff + l <= max_diff)
                    dp[offset + diff + l] = max(dp[offset + diff + l], old_dp[offset + diff] + l);
                if (diff - l >= min_diff)
                    dp[offset + diff - l] = max(dp[offset + diff - l], old_dp[offset + diff]);
            }
        }
        return dp[offset + 0];
    }
};

// bool dp[left][right] => if the we can get this pair (left,right)

// for(int i = 0; i < n; ++i)
// {
//     int l = rod[i];
//     for(int left = 0; left <= 2500; ++left)
//     {
//         for(int right = 0; right <= 2500; ++right)
//         {
//             if(dp[left][right] == true)
//             {
//                 dp[left+l][right] = true;
//                 dp[left][right+l] = true;
//             }

//             if(dp[left+l][right] && left+l == right)
//                 res = max(res, left+l);
//             if(dp[left][right+l] && left == right + l)
//                 res = max(res, left);
//         }
//     }
// }

// 上面设计 dp的方法是ok的， 但是会超时
// 其实只需记录 dp[diff] => longest left with diff, where diff = left - right

// for(int i = 0; i < n; ++i)
// {
//     for(diff = min_diff; diff <= max_diff; ++diff)
//     {
//         // 棍子加左边
//         dp[diff+l] = max(old_dp[diff]+l,old_dp[diff+l]);
//         // 棍子加右边
//         dp[diff-l] = max(old_dp[diff-l], old_dp[diff]);
//     }
// }

// return dp[0];
