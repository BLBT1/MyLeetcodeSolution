/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
    priority_queue<int, vector<int>, less<>> max_heap;    // the smaller half
    priority_queue<int, vector<int>, greater<>> min_heap; // the greater half

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num)
    {
        if (max_heap.empty() && min_heap.empty())
        {
            max_heap.push(num);
        }
        else
        {
            if (max_heap.top() <= num)
                min_heap.push(num);
            else
                max_heap.push(num);
        }

        if (min_heap.size() > max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        if (min_heap.size() + 1 < max_heap.size())
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian()
    {
        if (min_heap.size() == max_heap.size())
            return (min_heap.top() * 1.0 + max_heap.top() * 1.0) / 2.0;
        else
            return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
