```c++
class MyCalendar {
    map<int, int> cals; // {start -> end}
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        // check
        auto it = cals.lower_bound(startTime);
        if(it != cals.end() && it->first < endTime)
            return false;
        
        if(it != cals.begin())
            it--;
        else {
            // no other meeting before
            cals[startTime] = endTime;
            return true;
        }


        if(it->second > startTime)
            return false;
        
        cals[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

// check the s1 is >= e2
//     s1 ... e1
// s2 .... e2

// check the one meeting before s1's and s0 endTime < s2
// check the s1 is >= e
// s0 ... e0
//           s2 .... e2
```