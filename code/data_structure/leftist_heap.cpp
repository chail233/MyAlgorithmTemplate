int n,m;
array<int,maxn> lc,rc,dist,rt;
//左子节点，右子节点，Npl值，根
bool tf[maxn];//是否被删除
struct node {
    int id,v;
    bool operator < (const node &p) const {
        return v==p.v ? id<p.id : v<p.v;
    }
};
node v[maxn];
int find(int x) {
    if (x==rt[x]) return x;
    return rt[x] = find(rt[x]);//查找根节点
}
int merge(int x, int y) {
    //递归合并，将右子树与y堆合并
    if (!x || !y) return x+y;
    if (v[y]<v[x]) swap(x,y);
    rc[x] = merge(rc[x], y);
    if (dist[lc[x]]<dist[rc[x]]) swap(lc[x],rc[x]);
    //保证左偏性
    dist[x] = dist[rc[x]]+1;//更新Npl
    return x;
}
int main() {
    dist[0] = -1;
    cin >> n >> m;
    for (int i=1;i<=n;++i) {
        int vi;
        cin >> vi;
        rt[i]=i;
        v[i].id=i;
        v[i].v=vi;
    }
    while (m--) {
        int op;
        cin >> op;
        if (op==1) {
            int x,y;
            cin >> x >> y;
            if (tf[x] || tf[y]) continue;
            x = find(x);
            y = find(y);
            if (x!=y) rt[x] = rt[y] = merge(x,y);
        }
        else {
            int x;
            cin >> x;
            if (tf[x]) {
                cout << "-1\n";
                continue;
            }
            x = find(x);
            cout << v[x].v << "\n";
            tf[x] = true;
            rt[lc[x]] = rt[rc[x]] = rt[x]=merge(lc[x],rc[x]);
            //通过合并左右子树来删除堆的最小值，注意要记录x的根保证后续正确查询
            lc[x] = rc[x] = dist[x] = 0;
        }
    }
    return 0;
}
