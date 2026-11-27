// 返回 (有解?, 最小非负解)
pair<bool, ll> solve(ll a, ll b, ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    if (b % d != 0) return {false, 0};
    x = x * (b / d) % m;
    ll mod = m / d;
    x = (x % mod + mod) % mod;
    return {true, x};
}

// 若需要全部 d 个解
vector<ll> solve_all(ll a, ll b, ll m) {
    auto [ok, x0] = solve(a, b, m);
    if (!ok) return {};
    ll d = __gcd(a, m);
    vector<ll> res;
    ll mod = m / d;
    for (int k = 0; k < d; k++) {
        res.push_back((x0 + k * mod) % m);
    }
    return res;
}
