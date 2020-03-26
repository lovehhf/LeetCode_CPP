

/* 892. 三维形体的表面积
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
 */

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                res += grid[i][j] > 0 ? 2 : 0; // 底 + 订
                res += i > 0 ? max(grid[i][j] - grid[i - 1][j], 0) : grid[i][j];     // 上
                res += i < n - 1 ? max(grid[i][j] - grid[i + 1][j], 0) : grid[i][j]; // 下
                res += j > 0 ? max(grid[i][j] - grid[i][j - 1], 0) : grid[i][j];     // 左
                res += j < n - 1 ? max(grid[i][j] - grid[i][j + 1], 0) : grid[i][j]; //右
            }
        }

        return res;
    }
};