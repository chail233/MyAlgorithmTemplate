// 返回一组最长严格上升子序列，答案长度为 res.size()。
vector<int> lis(const vector<int>& a) {
    if (a.empty()) return {};

    int n = a.size();
    vector<int> tails, id, pre(n, -1);
    for (int i = 0; i < n; i++) {
        // tails[j] 记录长度为 j + 1 的子序列的最小末尾。
        int j = lower_bound(tails.begin(), tails.end(), a[i]) - tails.begin();
        if (j > 0) pre[i] = id[j - 1];

        if (j == (int)tails.size()) {
            tails.push_back(a[i]);
            id.push_back(i);
        } else {
            tails[j] = a[i];
            id[j] = i;
        }
    }

    vector<int> res;
    for (int i = id.back(); i != -1; i = pre[i]) {
        res.push_back(a[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
