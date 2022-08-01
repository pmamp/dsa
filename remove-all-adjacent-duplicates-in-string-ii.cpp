/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int> > dq;
        for (int i = 0; i < s.size(); ++i) {
            if (dq.size()) {
                auto pr = dq.back();
                if (pr.first == s[i]) {
                    dq.pop_back();
                    ++pr.second;
                    if (pr.second != k) dq.push_back(pr);
                }
                else {
                    dq.push_back({ s[i],1 });
                }

            }
            else {
                dq.push_back({ s[i],1 });
            }
        }
        string res = "";
        while (dq.size()) {
            for (int i = 0; i < dq.front().second; ++i)
                res.push_back(dq.front().first);

            dq.pop_front();
        }
        return res;
    }
};