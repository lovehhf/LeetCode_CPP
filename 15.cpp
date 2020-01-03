
/* 15. 3Sum
 * https://leetcode.com/problems/3sum/
 * 双指针
 * 时间复杂度 O(n^2) 空间复杂度O(n^2)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; i ++)
        {
            // 去掉最小值相同的情况
            if (i > 0 && nums[i] == nums[i -1]) continue;
            
            int l = i + 1, r = n - 1;
            while (l < r) {
                int t = nums[i] + nums[l] + nums[r];

                if (t == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    // 去掉l和r的重复情况
                    do{l ++;} while(l < r && nums[l - 1] == nums[l]);
                    do{r --;} while(l < r && nums[r + 1] == nums[r]);
                }
                else if (t < 0) l ++;
                else r --;
                
            }
        }
        return res;
    }
};