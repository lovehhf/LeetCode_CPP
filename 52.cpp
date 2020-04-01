

/*
 * 52. N皇后 II
 * 
 * 每行只能放一个皇后, 可以枚举皇后放在每行的哪一列, 时间复杂度 O(n!)
 *
 */



class Solution {
public:
    vector<bool> diag, anti_diag, col;
    int res = 0;

    void dfs(int n, int u) {  // u: 当前搜索到的行数
        if (u == n) {
            res ++;
            return;
        }

        // 枚举每行的皇后要放哪一列
        for (int i = 0; i < n; i ++) {
            if (col[i] || diag[i + u] || anti_diag[i - u + n]) continue;
            col[i] = diag[i + u] = anti_diag[i - u + n] = true;
            dfs(n, u + 1); // 搜索下一行
            col[i] = diag[i + u] = anti_diag[i - u + n] = false;
        }
    }

    int totalNQueens(int n) {
        anti_diag = diag = vector<bool>(2 * n, false);
        col = vector<bool>(n, false);
        dfs(n, 0);
        return res;
    }
};