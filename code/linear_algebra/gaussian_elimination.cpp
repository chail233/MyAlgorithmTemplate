// a 是增广矩阵，m 是未知数个数，每行最后一列为常数项。
// 返回 0 表示唯一解，1 表示无穷多解，2 表示无解。
int gauss(vector<vector<double>>& a, int m, vector<double>& x) {
    const double eps = 1e-9;
    int n = a.size(), r = 0;
    vector<int> col;

    for (int c = 0; c < m && r < n; c++) {
        int t = r;
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
        }
        if (fabs(a[t][c]) < eps) continue;

        swap(a[r], a[t]);
        for (int i = r + 1; i < n; i++) {
            double d = a[i][c] / a[r][c];
            a[i][c] = 0;
            for (int j = c + 1; j <= m; j++) a[i][j] -= d * a[r][j];
        }
        col.push_back(c);
        r++;
    }

    x.clear();
    for (int i = r; i < n; i++) {
        if (fabs(a[i][m]) >= eps) return 2;
    }

    // 自由变量取 0，从最后一个主元开始回代。
    x.assign(m, 0);
    for (int i = r - 1; i >= 0; i--) {
        int c = col[i];
        double b = a[i][m];
        for (int j = c + 1; j < m; j++) b -= a[i][j] * x[j];
        x[c] = b / a[i][c];
    }
    return r == m ? 0 : 1;
}
