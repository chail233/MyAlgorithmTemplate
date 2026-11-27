typedef long long ll;
// 扩展欧几里得算法
ll exgcd(ll a, ll b, ll &x, ll &y);

// 求逆元
ll inv(ll a, ll mod) {
    ll x, y;
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

// 中国剩余定理（模数互质）
// 输入：remainders余数数组，mods模数数组
// 输出：最小非负解x，满足 x ≡ r[i] (mod m[i])
ll CRT(vector<ll>& remainders, vector<ll>& mods) {
    int n = remainders.size();
    // 计算所有模数的乘积 M
    ll M = 1;
    for (int i = 0; i < n; i++) {
        M *= mods[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll Mi = M / mods[i];       // M/mi
        ll ti = inv(Mi, mods[i]);  // Mi在模mi下的逆元
        ans = (ans + remainders[i] * Mi % M * ti % M) % M;
    }
    return ans;
}
