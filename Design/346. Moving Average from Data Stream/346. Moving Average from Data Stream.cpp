class MovingAverage
{
    queue<int> q;
    int sz;
    int sum = 0;

public:
    MovingAverage(int size)
    {
        sz = size;
    }

    double next(int val)
    {
        if (q.size() < sz)
        {
            sum += val;
            q.push(val);
        }
        else
        {
            auto x = q.front();
            q.pop();
            sum -= x;
            q.push(val);
            sum += val;
        }
        return (sum * 1.0) / (q.size() * 1.0);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */