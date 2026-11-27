const int N = 1e5 + 10;

vector<pair<int, ll>> g[N];  // (v, w)
ll dp1[N], dp2[N];
ll ans = 0;  // 直径

void dfs(int u, int fa) {
    dp1[u] = dp2[u] = 0;
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        ll d = dp1[v] + w;
        if (d > dp1[u]) {
            dp2[u] = dp1[u];
            dp1[u] = d;
        }
        else if (d > dp2[u]) {
            dp2[u] = d;
        }
    }
    ans = max(ans, dp1[u] + dp2[u]);
}

// 调用
ll get_diameter() {
    ans = 0;
    dfs(1, 0);
    return ans;
}
