constexpr int maxn = 205;
constexpr int INF = 1e18;
struct e {
    int to,rev;
    int c;
};
vector<e> g[maxn];
int lv[maxn],cur[maxn];
int n,m,s,t;
void adde(int u,int v, int c) {
    g[u].push_back({v, (int)g[v].size(), c});
    g[v].push_back({u, (int)g[u].size()-1, 0});
}
bool bfs() {
    memset(lv,-1,sizeof(lv));
    queue<int> q;
    q.push(s);
    lv[s]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for (e& ei:g[u]) {
            if (ei.c>0 && lv[ei.to]==-1) {
                lv[ei.to]=lv[u]+1;
                q.push(ei.to);
            }
        }
    }
    return lv[t] != -1;
}
int dfs(int u, int sum) {
    if (u==t) return sum;
    int k,res=0;
    for (int i=cur[u];i<g[u].size() && sum;i++) {
        cur[u] = i;
        e& ei = g[u][i];
        if (ei.c>0 && lv[ei.to]==lv[u]+1) {
            k = dfs(ei.to,min(sum, ei.c));
            if (k==0) {
                lv[ei.to] = -1;
                continue;
            }
            ei.c-=k;
            g[ei.to][ei.rev].c+=k;
            res+=k;
            sum-=k;
        }
    }
    return res;
}
int Dinic() {
    int res = 0;
    while (bfs()) {
        memset(cur, 0, sizeof(cur));
        res += dfs(s,INF);
    }
    return res;
}
