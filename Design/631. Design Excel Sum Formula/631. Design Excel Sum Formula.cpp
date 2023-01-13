class Excel
{
    vector<vector<int>> mat;
    vector<vector<vector<string>>> exp;
    pair<int, char> parse(string &s)
    {
        int i = 0;
        while (i < s.size() && !isdigit(s[i]))
            ++i;
        int row = stoi(s.substr(i));
        char col = s[0];
        return {row, col};
    }

public:
    Excel(int height, char width)
    {
        mat = vector<vector<int>>(height + 1, vector<int>(width - 'A' + 1, 0));
        exp = vector<vector<vector<string>>>(27, vector<vector<string>>(26, vector<string>()));
    }

    // idea sum do not do calculation, only assign exp
    void set(int row, char col, int val)
    {
        mat[row][col - 'A'] = val;
        exp[row][col - 'A'].clear();
    }

    int get(int row, char col)
    {
        if (exp[row][col - 'A'].empty())
        {
            return mat[row][col - 'A'];
        }
        int res = 0;
        // nums => "F7" => single cell
        // "B3:F7" => i  in [3:7], j in [B:f]
        for (auto s : exp[row][col - 'A'])
        {
            int pos = s.find(":");
            if (pos != -1)
            {
                string begin = s.substr(0, pos);
                string end = s.substr(pos + 1);
                auto begPair = parse(begin);
                auto endPair = parse(end);

                for (int i = begPair.first; i <= endPair.first; ++i)
                    for (char j = begPair.second; j <= endPair.second; ++j)
                        res += get(i, j); // need to recursively get
            }
            else
            {
                auto p = parse(s);
                res += get(p.first, p.second);
            }
        }
        mat[row][col - 'A'] = res;
        return res;
    }

    int sum(int row, char col, vector<string> num)
    {
        exp[row][col - 'A'] = num;
        return get(row, col);
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */