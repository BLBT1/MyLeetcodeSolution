class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        vector<unordered_set<string>> head2suf(26);
        for (auto s : ideas)
        {
            char head = s[0];
            head2suf[head - 'a'].insert(s.substr(1));
        }

        long long res = 0;
        for (char a = 'a'; a <= 'z'; ++a)
            for (char b = 'a'; b <= 'z'; ++b)
            {
                if (a == b)
                    continue;
                int x = head2suf[a - 'a'].size();
                int y = head2suf[b - 'a'].size();

                // find commons
                int k = 0;
                for (string suf : head2suf[a - 'a'])
                {
                    if (head2suf[b - 'a'].find(suf) != head2suf[b - 'a'].end())
                        k += 1;
                }
                res += (x - k) * (y - k);
            }
        return res;
    }
};

// def {a} all suf started with a
// aA+bB => aB+bA,
// if aB is not appear in ideas, then B is not appear in {a}
// if bA is not appear in ideas, then A is not appear in {b}

// so if aB+bA is valid, then B and A should not be in any of {a},{b}
// so when counting, we should eliminate all common elements in {a} and {b}
// for prefix a,b
// x -> num of suf start with a
// y -> num of suf start with b
// k -> commons in suf start with a and suf start with b

// (x-k)*(y-k)*2
