

/*
 * 面试题13. 机器人的运动范围
 * https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 *
 * dfs
 */


class Solution {
public:
    bool vis[110][110];
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    bool check(int i, int j, int k) {
        // 检查能否进入 i, j
        int sum = 0;
        while(i) {
            sum += i % 10;
            i /= 10;
        }
        while(j) {
            sum += j % 10;
            j /= 10;
        }
        return sum <= k;
    }

    int dfs(int m, int n, int i, int j, int k) {
        int res = 1;
        vis[i][j] = true;
        for(int d = 0; d < 4; d ++) {
            // 搜索上下左右四个方向
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || !check(x, y, k)) continue;
            res += dfs(m, n, x, y, k);
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        memset(vis, 0, sizeof vis);
        return dfs(m, n, 0, 0, k);
    }
};