
/*
 * 48. 旋转图像
 * 顺时针旋转方阵
 * https://leetcode-cn.com/problems/rotate-image/
 * 顺时针: 先翻转每一列, 再交叉互换
 * 逆时针: 先翻转每一行, 再交叉互换
 */


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 翻转每一列
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n / 2; j ++)
            {
                swap(matrix[j][i], matrix[n - 1 - j][i]);
            }

        // 交叉互换 m[i][j], matrix[j][i]
        for(int i = 0; i < n; i ++)
            for (int j = 0; j < i + 1; j ++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }

    }
};