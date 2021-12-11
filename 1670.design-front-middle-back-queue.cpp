/*
 * @lc app=leetcode id=1670 lang=cpp
 *
 * [1670] Design Front Middle Back Queue
 */

// @lc code=start
class FrontMiddleBackQueue
{
    list<int> data;
    list<int>::iterator mid;
    int size;

public:
    FrontMiddleBackQueue() : size{0}, mid{nullptr} {}

    void pushFront(int val)
    {
        data.push_front(val);
        if (size == 0)
            mid = data.begin();
        else if (size % 2 == 1)
            mid = prev(mid);
        size++;
    }

    void pushMiddle(int val)
    {
        if (size == 0)
        {
            data.push_back(val);
            mid = data.begin();
        }
        else if (size % 2 == 0)
        {
            data.insert(next(mid), val);
            mid = next(mid);
        }
        else
        {
            data.insert(mid, val);
            mid = prev(mid);
        }
        size++;
    }

    void pushBack(int val)
    {
        data.push_back(val);
        if (size == 0)
            mid = data.begin();
        else if (size % 2 == 0)
            mid = next(mid);
        size++;
    }

    int popFront()
    {
        if (size == 0)
            return -1;
        int val = data.front();
        if (size % 2 == 0)
            mid = next(mid);
        data.pop_front();
        size--;
        return val;
    }

    int popMiddle()
    {
        if (size == 0)
            return -1;
        int val = *mid;

        //* after delete the node, the itr point to it is also gone,
        //* do we need to record the next mid before erase it
        auto mid_new = mid;
        if (size % 2 == 1)
            mid_new = prev(mid);
        else
            mid_new = next(mid);
        data.erase(mid);
        size--;
        mid = mid_new;
        return val;
    }

    int popBack()
    {
        if (size == 0)
            return -1;
        int val = data.back();
        //* must before pop, what if the list only has single node?
        if (size % 2 == 1)
            mid = prev(mid);
        data.pop_back();
        size--;
        return val;
    }
};
/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end
