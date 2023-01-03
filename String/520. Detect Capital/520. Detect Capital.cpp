class Solution {
public:
    bool detectCapitalUse(string w)
    {
        // 如果第一个字母是小写，后面前要是小写
        // 如果第一个字母是大写，后面either全是大写或全是小写
        if(!isupper(w[0]))
        {
            for(int i = 1; i < w.size(); ++i)
            {
                if(isupper(w[i]))
                    return false;
            }
        }
        else
        {
            for(int i = 2; i < w.size(); ++i)
            {
                if(isupper(w[i-1]) != isupper(w[i]))
                   return false; 
            }
        }
        return true;
    }
};