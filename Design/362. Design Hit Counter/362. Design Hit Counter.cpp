class HitCounter
{
    deque<pair<int, int>> dq;
    int cnt = 0;

public:
    HitCounter() {}

    void hit(int t)
    {
        if (!dq.empty() && dq.front().first == t)
        {
            cnt += 1;
            dq.front().second += 1;
        }
        else
        {
            cnt += 1;
            dq.push_front({t, 1});
        }
    }

    int getHits(int t)
    {
        while (!dq.empty() && dq.back().first <= t - 300)
        {
            cnt -= dq.back().second;
            dq.pop_back();
        }
        return cnt;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */