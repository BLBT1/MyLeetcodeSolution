class Solution
{
    unordered_map<char, char> father;

public:
    string smallestEquivalentString(string s1,
                                    string s2,
                                    string base)
    {
        // idea: use union find, make sure the father is the lowest in lexicographic
        for (char c = 'a'; c <= 'z'; ++c)
            father[c] = c;

        for (int i = 0; i < s1.size(); ++i)
        {
            char c1 = s1[i], c2 = s2[i];
            if (findFather(c1) != findFather(c2))
                myUnion(c1, c2);
        }

        string res;
        for (auto b : base)
        {
            res.push_back(findFather(b));
        }
        return res;
    }

    char findFather(char c)
    {
        if (c == father[c])
            return c;
        father[c] = findFather(father[c]);
        return father[c];
    }

    void myUnion(char c1, char c2)
    {
        c1 = findFather(c1);
        c2 = findFather(c2);
        if (c1 < c2)
            father[c2] = c1;
        else
            father[c1] = c2;
    }
};