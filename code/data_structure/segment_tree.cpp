const int N = 100005;
struct node{
    int l, r;
    int sum;
    int lz;
};
node tr[N*4];
int a[N];
void pushup(int u){
    tr[u].sum = tr[u*2].sum+tr[u*2+1].sum;
}
void build(int u, int l, int r){
    tr[u] = {l,r,0,0};
    if(l==r){
        tr[u].sum = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(u*2, l, mid);
    build(u*2+1, mid+1, r);
    pushup(u);
}
void pushdown(int u){
    if(tr[u].lz){
        int lazy = tr[u].lz;
        tr[u*2].sum += lazy * (tr[u*2].r-tr[u*2].l+1);
        tr[u*2].lz+=lazy;
        tr[u*2+1].sum += lazy * (tr[u*2+1].r-tr[u*2+1].l+1);
        tr[u*2+1].lz+=lazy;
    }
    tr[u].lz = 0;
}
void modify(int u, int l, int r, int d){
    if(tr[u].l>=l && tr[u].r<=r){
        tr[u].sum += d * (tr[u].r-tr[u].l+1);
        tr[u].lz += d;
        return;
    }
    pushdown(u);
    int mid = (tr[u].l+tr[u].r)/2;
    if(l<=mid) modify(u*2, l, r, d);
    if(r>mid) modify(u*2+1, l, r, d);
    pushup(u);
}
int query(int u, int l, int r){
    if(tr[u].l>=l && tr[u].r<=r){
        return tr[u].sum;
    }
    pushdown(u);
    int res = 0;
    int mid = (tr[u].l+tr[u].r)/2;
    if(l<=mid) res += query(u*2, l, r);
    if(r>mid) res += query(u*2+1, l, r);
    return res;
}
