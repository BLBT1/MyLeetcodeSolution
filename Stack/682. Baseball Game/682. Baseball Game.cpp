class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> rec;
        int sum = 0;
        for (int i = 0; i < ops.size(); ++i)
        {
            if (ops[i] == "+")
            {
                auto f = rec.top();
                rec.pop();
                auto s = rec.top();
                int x = f + s;
                rec.push(f);
                rec.push(x);
            }
            else if (ops[i] == "D")
            {
                auto f = rec.top();
                rec.push(f * 2);
            }
            else if (ops[i] == "C")
            {
                rec.pop();
            }
            else
            {
                rec.push(stoi(ops[i]));
            }
        }

        while (!rec.empty())
        {
            sum += rec.top();
            rec.pop();
        }

        return sum;
    }
};