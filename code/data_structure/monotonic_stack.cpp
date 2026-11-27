// 返回每个位置左、右两侧最近的严格更小元素下标，不存在时为 -1。
pair<vector<int>, vector<int>> nearest_less(const vector<int>& a) {
    int n = a.size();
    vector<int> l(n, -1), r(n, -1);
    vector<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
        if (!stk.empty()) l[i] = stk.back();
        stk.push_back(i);
    }

    stk.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
        if (!stk.empty()) r[i] = stk.back();
        stk.push_back(i);
    }
    return {l, r};
}
