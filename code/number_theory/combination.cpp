// 预处理到 n，要求 0 <= n < mod 且 mod 为素数。
struct Combination {
    int mod;
    vector<int> fac, ifac;

    Combination(int n, int p = 1000000007) : mod(p), fac(n + 1), ifac(n + 1) {
        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;

        ifac[n] = qpow(fac[n], mod - 2);
        for (int i = n; i > 0; i--) ifac[i - 1] = 1LL * ifac[i] * i % mod;
    }

    int qpow(long long a, int b) const {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    // n 不能超过预处理上界，非法 k 的组合数为 0。
    int C(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return 1LL * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
    }
};
