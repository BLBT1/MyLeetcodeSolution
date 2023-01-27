class Solution
{
public:
    string breakPalindrome(string pali)
    {
        if (pali.size() == 1)
            return "";
        for (int i = 0; i < pali.size(); ++i)
        {
            if (pali[i] != 'a' && i != pali.size() / 2)
            {
                pali[i] = 'a';
                return pali;
            }
        }
        pali[pali.size() - 1] = 'b';
        return pali;
    }
};