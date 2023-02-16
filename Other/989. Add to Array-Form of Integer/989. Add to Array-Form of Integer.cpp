class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> k_num;
        while (k != 0)
        {
            k_num.push_back(k % 10);
            k /= 10;
        }
        reverse(k_num.begin(), k_num.end());
        int carry = 0;
        int i = num.size() - 1;
        int j = k_num.size() - 1;
        while (i >= 0 || carry != 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += num[i];
            if (j >= 0)
                sum += k_num[j];
            carry = sum / 10;
            if (i >= 0)
                num[i] = sum % 10;
            else if (j >= 0)
                num.insert(num.begin(), sum % 10);
            else
                num.insert(num.begin(), 1);
            --i;
            --j;
        }
        // if k_num longer then num
        while (j >= 0)
        {
            int sum = k_num[j] + carry;
            carry = sum / 10;
            num.insert(num.begin(), sum % 10);
            --j;
        }
        if (carry == 1)
        {
            num.insert(num.begin(), 1);
        }
        return num;
    }
};