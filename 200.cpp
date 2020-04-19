
/*
200. 岛屿数量
链接：https://leetcode-cn.com/problems/number-of-islands

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1:
输入:
11110
11010
11000
00000
输出: 1

示例 2:
输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。


并查集解法, 每个岛屿组成一个集合, 求所有集合的数量
*/

class UnionFind {
public:
    vector<int> father;

    UnionFind(int n) {
        for (int i = 0; i < n; i ++) father.push_back(i);
    }

    // 查找祖先节点
    int find(int x) {
        if (x == father[x]) return x;
        father[x] = find(father[x]);  // 路径压缩
        return father[x];
    }

    // union 名字不能用, 使用 merge 函数表示合并2个集合
    void merge(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        father[fa] = fb;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size(), n = grid[0].size();

        UnionFind uf(m * n);
        vector<pair<int, int>> ds = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] != '1') continue;
                for (int k = 0; k < 4; k ++) {
                    int x = i + ds[k].first;
                    int y = j + ds[k].second;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') continue;
                    uf.merge(i * n + j, x * n + y);   // 合并两个点所在的集合
                }
            }
        }

        int res = 0;
        // 查找并查集中的 1 组成了多少个集合
        for (int i = 0; i < m * n; i ++) {
            if (grid[i / n][i % n] == '1' && i == uf.father[i]) res ++;
        }

        return res;
    }
};