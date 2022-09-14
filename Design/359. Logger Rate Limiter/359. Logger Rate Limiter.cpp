class Logger
{
    unordered_map<string, int> mp;

public:
    Logger() {}

    bool shouldPrintMessage(int time, string msg)
    {
        if (mp.find(msg) != mp.end() && time - mp[msg] < 10)
            return false;

        mp[msg] = time;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */