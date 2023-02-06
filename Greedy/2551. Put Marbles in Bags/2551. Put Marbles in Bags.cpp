class Solution
{
public:
    long long putMarbles(vector<int> &weights, int K)
    {
        int n = weights.size();
        vector<int> pairs;
        for (int i = 1; i < n; ++i)
            pairs.push_back(weights[i - 1] + weights[i]);
        sort(pairs.rbegin(), pairs.rend());
        long long maxScore = 0;
        long long minScore = 0;
        for (int i = 0; i < K - 1; ++i)
        {
            maxScore += pairs[i];
            minScore += pairs[n - 1 - i - 1];
        }
        return maxScore - minScore;
    }
};

// 这道题可以用区间1型dp来做
// find max score
// def: dp[i][k] => max score we can get using the first i marble and spliting into k bags, where i <= n && k <= K
// for(i = 1; i <= n; ++i)
//     for(int k = 1; k <= min(i, K); ++k)
//         for(int j = i; j > k-1; --j)
//             dp[i][k] = max(dp[i][k], dp[j-1][k-1]+weights[j]+weights[i])
// 同样的方式我们可以再找到可能的min score，相减得到答案
// time 是 O(N*N*K) = 10^9 * 10*9 *10^5 > 10^6 肯定超时

// Greedy的方法
// [XX XX XXX XX]
// 这道题目要求把nums分成k个subarray， 找出每个区间的头和尾的和， 所以我们想
// - 不管怎么分， nums的头和尾肯定是加到final的score里的
// - 中间其实是插入k-1块板，把nums分给开来，因为score算上的是每个区间的头和尾，所以其实这块插进去的板的两边（分别是上一个去接的尾巴和下一个区间的头） 也都是要算进去的
// - 所以score其实是nums的头尾+中间找k-1 个连续的pair之和
// - 那我们可以找到所有的连续区间 再排序找到头k-1个和尾巴k-1的和的差就是
// - O(nlogn) =>
