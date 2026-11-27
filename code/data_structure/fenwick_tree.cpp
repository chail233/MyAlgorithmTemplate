// 下标从 1 开始，支持单点加和区间求和。
struct Fenwick {
    int n;
    vector<long long> tr;

    explicit Fenwick(int n) : n(n), tr(n + 1LL) {}

    void add(int x, long long d) {
        for (long long i = x; i <= n; i += i & -i) tr[i] += d;
    }

    long long sum(int x) const {
        long long res = 0;
        for (int i = x; i > 0; i -= i & -i) res += tr[i];
        return res;
    }

    long long query(int l, int r) const {
        return sum(r) - sum(l - 1);
    }
};
