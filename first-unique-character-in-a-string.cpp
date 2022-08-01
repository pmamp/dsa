/*
https://leetcode.com/problems/first-unique-character-in-a-string/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size(), ans = -1;
        vector<int> a(26, 0);
        for (int i = 0; i < n; ++i) {
            a[(s[i] - 97)] += 1;
        }
        for (int i = 0; i < n; ++i) {
            if (a[(s[i] - 97)] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};