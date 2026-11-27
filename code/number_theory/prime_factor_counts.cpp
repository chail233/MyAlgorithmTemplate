int omega[N], Omega[N];  // 不同 / 计重
bool st[N];
int primes[N], cnt;

void prework(int n) {
    omega[1] = Omega[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            omega[i] = 1;  // 素数有 1 个不同质因子
            Omega[i] = 1;  // 素数有 1 个质因子（计重）
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = i * primes[j];
            st[t] = true;
            if (i % primes[j] == 0) {
                omega[t] = omega[i];      // 无新增质因子
                Omega[t] = Omega[i] + 1;  // 指数 +1
                break;
            }
            omega[t] = omega[i] + 1;     // 新增一个质因子
            Omega[t] = Omega[i] + 1;
        }
    }
}
