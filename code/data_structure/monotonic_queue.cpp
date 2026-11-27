// 求长度为 k 的滑动窗口最值，get_max 为 false 时求最小值。
vector<int> sliding_window(const vector<int>& a, int k, bool get_max = true) {
    int n = a.size();
    if (k <= 0 || k > n) return {};

    deque<int> q;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        while (!q.empty()) {
            int j = q.back();
            if (get_max ? a[j] > a[i] : a[j] < a[i]) break;
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1) res.push_back(a[q.front()]);
    }
    return res;
}
