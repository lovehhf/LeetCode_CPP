


/* https://leetcode-cn.com/problems/distribute-candies-to-people/
 * 1103. 分糖果 II
 */

class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n, 0);
        for (int i = 1; candies > 0; i ++) {
            int idx = (i - 1) % n;
            res[idx] += i < candies ? i : candies;
            candies -= i;
        }

        return res;
    }
};