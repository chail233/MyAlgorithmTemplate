const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;
vector<int> g[N];          // 原图

int dfn[N], low[N], timer;
int stk[N], top;
bool in_stk[N];
int scc[N], scc_cnt;       // scc[i] = i 所属 SCC 编号
int sz[N];                 // sz[i] = SCC i 的大小

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk[++top] = u;
    in_stk[u] = true;

    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    // 找到一个 SCC
    if (dfn[u] == low[u]) {
        scc_cnt++;
        int v;
        do {
            v = stk[top--];
            in_stk[v] = false;
            scc[v] = scc_cnt;
            sz[scc_cnt]++;
        } while (v != u);
    }
}

// 缩点建新图
vector<int> ng[N];         // DAG
int in[N];                 // 入度（拓扑排序用）

void build_dag() {
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);  // 不连通时
    }
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (scc[u] != scc[v]) {
                ng[scc[u]].push_back(scc[v]);
                in[scc[v]]++;
            }
        }
    }
    // 可选：DAG 去重边
    for (int i = 1; i <= scc_cnt; i++) {
        sort(ng[i].begin(), ng[i].end());
        ng[i].erase(unique(ng[i].begin(), ng[i].end()), ng[i].end());
    }
}
