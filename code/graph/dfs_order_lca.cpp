constexpr int N = 5e5 + 5;
int n, m, R;
int dn;
int dfn[N];
int mi[19][N];
vector<int> e[N];
int get(int x, int y) {
    return dfn[x] < dfn[y] ? x : y;
}
void dfs(int id, int f) {
    dfn[id] = ++dn;
    mi[0][dn] = f;
    for (int it : e[id]) {
        if (it != f) dfs(it, id);
    }
}
int lca(int u, int v) {
    if (u == v) return u;
    if ((u = dfn[u]) > (v = dfn[v])) swap(u, v);
    int d = __lg(v - u);
    u++;
    return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> R;
    for (int i = 2, u, v; i <= n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(R, 0);
    for (int i = 1; i <= __lg(n); i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            mi[i][j] = get(mi[i - 1][j],
             mi[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}
