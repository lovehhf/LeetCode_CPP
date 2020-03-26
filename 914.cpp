


/* 914. 卡牌分组
 * https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/
 *
 * 统计次数, 求最大公因数
 */

class Solution {
public:

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> ht;
        for(int num:deck) ht[num] ++;
        int cnt = ht[deck[0]];

        for(auto item:ht) {
            cnt = gcd(cnt, item.second);
            if (cnt < 2) return false;
        }

        return true;
    }
};