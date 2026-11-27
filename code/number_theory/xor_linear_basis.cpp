// 异或线性基（求最大值/最小值/k小值/排名）
struct LinearBasis {
    static const int MAXL = 63;  // 处理64位整数
    long long basis[MAXL + 5];   // basis[i] 表示最高位为i的基
    int dim;                     // 线性基的维数（秩）

    LinearBasis() {
        memset(basis, 0, sizeof(basis));
        dim = 0;
    }

    // 插入一个数（标准高斯消元形式）
    bool insert(long long x) {
        for (int i = MAXL; i >= 0; i--) {
            if (!(x >> i & 1)) continue;  // x的第i位为0就跳过
            if (!basis[i]) {
                basis[i] = x;
                dim++;
                return true;  // 插入成功
            }
            x ^= basis[i];
        }
        return false;  // 插入失败，x能被当前基表示
    }

    // 查询异或最大值（对0异或）
    long long queryMax() {
        long long res = 0;
        for (int i = MAXL; i >= 0; i--) {
            if ((res ^ basis[i]) > res) {
                res ^= basis[i];
            }
        }
        return res;
    }

    // 查询异或最小值（非0的最小值）
    long long queryMin() {
        for (int i = 0; i <= MAXL; i++) {
            if (basis[i]) return basis[i];
        }
        return 0;
    }

    // 判断一个数能否被线性基表示
    bool contains(long long x) {
        for (int i = MAXL; i >= 0; i--) {
            if (x >> i & 1) {
                if (!basis[i]) return false;
                x ^= basis[i];
            }
        }
        return true;
    }
