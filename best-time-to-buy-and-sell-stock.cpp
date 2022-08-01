/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),
            ans = 0;
        vector<int> rightmax(n, 0);
        for (int i = n - 1 - 1; i >= 0; --i) {
            rightmax[i] = max(rightmax[i + 1], prices[i + 1]);
        }
        for (int i = 0; i < n - 1; ++i) {
            int profit = (rightmax[i] - prices[i]);
            if (ans < profit)
                ans = profit;
        }
        return ans;
    }
};