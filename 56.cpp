


/* 56. 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/
 *
 * 合并区间, 预排序
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 0; i < intervals.size(); i ++) {
            int k = res.size() - 1;
            int a = res[k][0], b = res[k][1];
            int c = intervals[i][0], d = intervals[i][1];
            if (c > b) res.push_back(intervals[i]);  // 没有重叠区间
            else {
                res[k][0] = a;
                res[k][1] = max(b, d);
            }
        }

        return res;
    }
};