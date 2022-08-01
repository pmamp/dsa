/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);
        int back = 0, front = -1, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]] > 0) {
                while (count[s[i]]) {
                    --count[s[back]];
                    ++back;
                }
            }
            ++count[s[i]];
            ++front;
            ans = max(ans, front - back + 1);
            // cout<< ans << " f "<< front << " b "<<back <<"\n";
        }
        return ans;
    }
};