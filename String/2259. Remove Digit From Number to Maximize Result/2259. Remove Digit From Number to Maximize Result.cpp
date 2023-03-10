class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        bool flag = false;
        for (int i = 0; i < number.size() - 1; ++i)
        {
            if (flag == false && number[i] < number[i + 1] && number[i] == digit)
            {
                flag = true;
                number.erase(number.begin() + i);
                break;
            }
        }

        if (flag == false)
        {
            for (int i = number.size() - 1; i >= 0; --i)
            {
                if (number[i] == digit)
                {
                    number.erase(number.begin() + i);
                    break;
                }
            }
        }
        return number;
    }
};