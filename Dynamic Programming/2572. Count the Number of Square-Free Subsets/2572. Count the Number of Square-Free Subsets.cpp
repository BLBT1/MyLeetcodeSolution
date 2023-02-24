class Solution
{
    using LL = long long;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

public:
    int squareFreeSubsets(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        LL dp[1001][1025];
        LL res = 0;

        const LL Mod = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int state = 0; state < (1 << 10); ++state)
            {
                if (nums[i] == 1)
                    dp[i][state] = (dp[i - 1][state] * 2) % Mod;
                else
                {
                    dp[i][state] = dp[i - 1][state] % Mod;
                    // encode return -1 if nums[i] can be divided by a square num
                    int s = encode(nums[i]);
                    if (s != -1 && (state & s) == s)
                        dp[i][state] = (dp[i][state] + dp[i - 1][state - s]) % Mod;
                }
                if (i == n)
                    res = (res + dp[i][state]) % Mod;
            }
        }

        return (res + Mod - 1) % Mod;
    }

    int encode(int x)
    {
        int s = 0;
        for (int i = 0; i < primes.size(); i++)
        {
            int count = 0;
            while (x % primes[i] == 0)
            {
                count++;
                x /= primes[i];
            }
            if (count > 1)
                return -1;
            else if (count == 1)
                s += (1 << i);
        }
        return s;
    }
};

// an array is sqare free => if product of array is squre free, all the prime divisor only appear once
// => find all subset such that all the prime only appear one

// 2^10 possible subset => 2^10 for 1 => pick ith prime, 0 => not pick ith prime
// [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
// we can use a 10 bits binary to present the state of a subset.

// dp[i][state] : for first ith nums, has # subset of state

// we can also represent nums[i] as a state s, nums[i] can be picked iff:
// (1) nums[i] is not a sqaure num / nums[i] only contains one time at most of each prime as divisor
// (2) state contians s, that is all the possible prime in nums[i], must also contains in state
//     that is (state & s) == s

// for each nums, we need to add num subset if take this num and num subset if not take this nums
// if nums[i] == 1, then we can take and not take, do not matter

// res: sum of all states