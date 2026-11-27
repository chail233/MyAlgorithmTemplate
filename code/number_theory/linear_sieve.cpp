vector<ll> gp(int n) {
    vector<ll> ps;
    vector<bool> isp(n + 1, true);
    isp[0] = isp[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isp[i]) ps.push_back(i);
        for (ll p : ps) {
            if (i * p > n) break;
            isp[i * p] = false;
            if (i % p == 0) break;
        }
    }
    return ps;
}
