// 先用线性筛预处理 sqrt(N) 内的素数
// 再用素数试除，避免枚举合数

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;
    for (int i = 0; i < cnt &&
    (ll)primes[i] * primes[i] <= n; i++) {
        ll p = primes[i];
        if (n % p == 0) {
            int c = 0;
            while (n % p == 0) n /= p, c++;
            res.push_back({p, c});
        }
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}
