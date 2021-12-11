/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start

class MyCalendar
{
public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto ceil = data.lower_bound(start);
        if (ceil != data.cend() && ceil->first < end)
        {
            return false;
        }

        //* prev do not modify itr
        if (ceil != data.cbegin() && prev(ceil)->second > start)
        {
            return false;
        }

        data[start] = end;

        return true;
    }

private:
    std::map<int, int> data;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
