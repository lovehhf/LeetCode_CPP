

/* 506. 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/
 *
 * 语法题, 带索引排序
 */


#define PII pair<int, int>
#define MP make_pair

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> res(n);

        vector<PII> tmp;
        for(int i = 0; i < n; i ++) {
            tmp.push_back(MP(nums[i], i));
        }

        sort(tmp.rbegin(), tmp.rend());

        for (int i = 0; i < min(n, 3); i ++) {
            int idx = tmp[i].second;
            switch(i) {
                case 0:
                    res[idx] = "Gold Medal";
                    break;
                case 1:
                    res[idx] = "Silver Medal";
                    break;
                case 2:
                    res[idx] = "Bronze Medal";
                    break;
            }
        }

        for(int i = 3; i < n; i ++) {
            int idx = tmp[i].second;
            res[idx] = to_string(i + 1);
        }

        return res;
    }
};