
/* 121. 买卖股票的最佳时机
 * 原题链接: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 *
 * 贪心: 遍历, 记录最大收益和遍历到的最小值, 找出之前的最小值与当前价格比较, 如果当前价格 - 之前最小值大于之前计算出的最大收益, 则更新最大收益
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = 0x3f3f3f3f;
        for (int price:prices) {
            if (price < min_price) min_price = price;
            else res = max(res, price - min_price);
        }
        return res;
    }
};