int n,m,s,t;
struct e {
    int t,w,c;
    int rev;
};
vector<e> g[maxn];
array<int,maxn> dist,cur;
array<bool, maxn> vis;
void addEdge(int u,int v, int w, int c) {
    g[u].push_back({v,w,c, (int)g[v].size()});
    g[v].push_back({u,0,-c, (int)g[u].size()-1});
}
bool spfa() {
    //spfa寻找最短路并建立分层图
    dist.fill(1e9);
    array<bool,maxn> inq{};
    queue<int> q;
    dist[s] = 0;
    inq[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (e& ei:g[u]) {
            if (ei.w && dist[u]+ei.c < dist[ei.t]) {
                dist[ei.t] = dist[u]+ei.c;
                if (!inq[ei.t]) {
                    inq[ei.t] = true;
                    q.push(ei.t);
                }
            }
        }
    }
    return dist[t] < 1e9;
}
int dfs(int u, int lim) {
    if (u==t) return lim;
    vis[u] = true;
    int res = 0;
    int k;
    for (int i=cur[u];i<g[u].size() && lim;++i) {
        cur[u] = i;
        e& ei = g[u][i];
        if (ei.w && dist[u]+ei.c==dist[ei.t] && !vis[ei.t]) {
            k = dfs(ei.t, min(lim, ei.w));
            if (!k) {
                dist[ei.t] = -1;
                continue;
            }
            ei.w-=k;
            g[ei.t][ei.rev].w+=k;
            res += k;
            lim -= k;
        }
    }
    vis[u] = false;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s >> t;
    for (int i=1;i<=m;++i) {
        int u,v,w,c;
        cin >> u >> v >> w >> c;
        addEdge(u,v,w,c);
    }
    int maxflow=0;
    int mincost=0;
    while (spfa()) {
        cur.fill(0);
        //dinic寻找增广路
        while (int flow=dfs(s, 0x3f3f3f)) {
            maxflow += flow;
            mincost += flow*dist[t];
        }
    }
    cout << maxflow << " " << mincost << endl;
    return 0;
}
