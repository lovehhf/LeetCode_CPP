



/* 473. 火柴拼正方形
 * 
 * dfs+剪枝
 *
 */


class Solution {
public:
    vector<bool> vis; // 访问过的火柴
    int side; // 边长
    
    bool dfs(vector<int>& nums, int u, int count,int target) {
        // printf("%d %d %d\n", u, count, target);

        if (target == 0) {
            if(count == 3) return true;            
            return dfs(nums, 0, count + 1, side);
        }

        for (int i = u; i < nums.size(); i ++) {
            if(vis[i] || target < nums[i]) continue;
            vis[i] = true;
            if (dfs(nums, i + 1, count, target - nums[i])) return true;
            vis[i] = false;
        }

        return false;
    }
 
    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;

        int c = 0;
        for (int num:nums) c += num;
        if (c & 3) return false; // 不能被4整除

        vis = vector<bool>(nums.size());
        side = c >> 2;
        
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        return dfs(nums, 0, 0, side);
    }
};