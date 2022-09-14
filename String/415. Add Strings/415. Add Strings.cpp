class Solution
{
public:
    string addStrings(string num1,
                      string num2)
    {
        string sum = "";
        int carry = 0;
        while (!num1.empty() && !num2.empty())
        {
            int x = (num1.back() - '0') + (num2.back() - '0') + carry;
            sum.push_back(x % 10 + '0');
            carry = x / 10;
            num1.pop_back();
            num2.pop_back();
        }

        while (!num1.empty())
        {
            int x = (num1.back() - '0') + carry;
            sum.push_back(x % 10 + '0');
            carry = x / 10;
            num1.pop_back();
        }

        while (!num2.empty())
        {
            int x = (num2.back() - '0') + carry;
            sum.push_back(x % 10 + '0');
            carry = x / 10;
            num2.pop_back();
        }

        if (carry != 0)
            sum.push_back('1');

        reverse(sum.begin(), sum.end());
        return sum;
    }
};