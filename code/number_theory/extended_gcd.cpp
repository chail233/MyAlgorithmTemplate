int exgcd(int a, int b, int &x, int &y)
// 扩展欧几里得算法, 求x, y，使得ax + by = gcd(a, b)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    //d始终都是a和b的最大公约数, 倒着传参是为了简化计算
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
    //返回d，使得能够在求最大公约数的同时完成x，y的凑整
    //若gcd(a, b)=1，x为a在模b意义下的逆元
}
