
/* 1162. 地图分析
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/
 *
 * 多源最短路, 和 542. 01 矩阵, 994. 腐烂的橘子 类似
 *
 */

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        int res = -1;

        queue<vector<int>> q;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if(grid[i][j] == 1) q.push({i, j, 0});
            }
        }

        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int i = cur[0], j = cur[1], t = cur[2];
            for(int k = 0; k < 4; k ++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0) continue;
                grid[x][y] = t + 1;
                q.push({x, y, t + 1});
                res = max(res, t + 1);
            }
        }

        return res;
    }
};