/*
https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector< vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            pq.push({ intervals[i][0], intervals[i][1] });
        }
        while (pq.size() > 1) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            if (p1.second >= p2.first) {
                int mx = max(p1.second, p2.second);
                pq.push({ p1.first, mx });
            }
            else {
                vector<int> v;
                v.push_back(p1.first);
                v.push_back(p1.second);
                res.push_back(v);
                pq.push(p2);
            }
        }
        auto p1 = pq.top();
        vector<int> v;
        v.push_back(p1.first);
        v.push_back(p1.second);
        res.push_back(v);

        return res;
    }
};