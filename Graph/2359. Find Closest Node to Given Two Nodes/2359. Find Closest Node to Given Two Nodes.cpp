class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        dist(edges, node1, dist1);
        dist(edges, node2, dist2);
        int res = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < edges.size(); ++i)
        {
            if (dist1[i] == -1 || dist2[i] == -1)
                continue;

            int mx = max(dist1[i], dist2[i]);
            if (mx < minDist)
            {
                minDist = mx;
                res = i;
            }
            else if (mx == minDist && i < res)
            {
                minDist = mx;
                res = i;
            }
        }
        return res;
    }

    void dist(vector<int> &edges, int node, vector<int> &dist_vec)
    {
        int curr = node;
        int d = 0;
        dist_vec[node] = 0;
        while (edges[curr] != -1 && dist_vec[edges[curr]] == -1)
        {
            int next = edges[curr];
            dist_vec[next] = dist_vec[curr] + 1;
            curr = next;
        }
    }
};