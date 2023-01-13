class MedianFinder
{
    priority_queue<int, vector<int>, greater<>> larger; // a min heap for the larger half
    priority_queue<int, vector<int>, less<>> smaller;   // a max heap for the
public:
    MedianFinder() {}

    // want to make sure |smaller| - |larger| <= 1
    void addNum(int num)
    {
        if (larger.size() == 0 && smaller.size() == 0)
            smaller.push(num);
        else
            // 比小的头小的放小， 比大的头大的放大
            if (smaller.top() >= num)
                smaller.push(num);
            else
                larger.push(num);

        if (smaller.size() - 2 == larger.size())
        {
            larger.push(smaller.top());
            smaller.pop();
        }
        else if (larger.size() > smaller.size())
        {
            smaller.push(larger.top());
            larger.pop();
        }
    }

    double findMedian()
    {
        if (smaller.size() > larger.size())
            return smaller.top();
        else
            return (smaller.top() * 1.0 + larger.top() * 1.0) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// smaller half => max heap
// larger half => min heap

// 1, 2, 3, 4, 5, 6, 7
