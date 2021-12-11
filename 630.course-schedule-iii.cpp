/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution
{

public:
    struct myCmp
    {
        bool operator()(vector<int> &c1, vector<int> &c2)
        {
            return c1[1] < c2[1];
        }
    };

    int scheduleCourse(vector<vector<int>> &courses)
    {
        // in many similiar problems
        // if a ddl is given, then it is most important
        // using pattern of sort + pq

        // asc. for ddl
        sort(courses.begin(), courses.end(), myCmp());
        int day = 0;
        priority_queue<int, vector<int>, less<>> chosenCourse;

        for (int i = 0; i < courses.size(); ++i)
        {
            chosenCourse.push(courses[i][0]);
            day += courses[i][0];

            if (day > courses[i][1])
            {
                day -= chosenCourse.top();
                chosenCourse.pop();
            }
        } //for

        return chosenCourse.size();
    }
};
// @lc code=end
