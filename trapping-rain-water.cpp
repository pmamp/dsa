/*

https://leetcode.com/problems/trapping-rain-water/

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> lMax(n, 0);
        vector<int> rMax(n, 0);
        lMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            lMax[i] = max(lMax[i - 1], height[i]);
            // cout<< lMax[i] << " ";
        }
        // cout<<"\n";
        rMax[n - 1] = height[n - 1];
        for (int i = n - 2; i > -1; --i) {
            rMax[i] = max(rMax[i + 1], height[i]);
            // cout<<rMax[i] << " ";
        }
        // cout<<"\n";

        for (int i = 0; i < n; ++i) {
            ans += min(lMax[i], rMax[i]) - height[i];
        }
        return ans;
    }
};