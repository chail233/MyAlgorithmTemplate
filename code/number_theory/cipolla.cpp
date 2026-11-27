struct Complex {  // 扩域元素
    ll real, imag;  // real + imag * omega
    Complex(ll r = 0, ll i = 0) : real(r), imag(i) {}
};

ll w;  // omega^2 = w (即 r^2 - a)
ll p;  // 模数

Complex mul(const Complex& a, const Complex& b) {
    Complex res;
    res.real = (a.real * b.real + a.imag * b.imag % p * w) % p;
    res.imag = (a.real * b.imag + a.imag * b.real) % p;
    return res;
}

Complex qpow(Complex a, ll b) {
    Complex res(1, 0);
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

// Cipolla 求 x^2 ≡ n (mod p)
// 返回 (有解?, 解x)，另一个解为 p-x
pair<bool, ll> cipolla(ll n, ll prime) {
    p = prime;
    if (n == 0) return {true, 0};
    if (qpow(n, (p - 1) / 2) != 1) return {false, 0};
    // 非二次剩余

    // 随机找 r 使 r^2 - n 是非二次剩余
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ll> dist(0, p - 1);
    ll r;
    do {
        r = dist(rng);
        w = (r * r % p - n + p) % p;
    } while (qpow(w, (p - 1) / 2) != p - 1);

    Complex base(r, 1);
    Complex ans = qpow(base, (p + 1) / 2);
    return {true, ans.real};
}

// 使用示例
// auto [ok, x] = cipolla(a, p);
// 另一解: p - x
