#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;

int a[N], d[N], l[N], spend[N];
//a表示鱼塘能钓到的鱼的数量，d表示鱼塘每天的鱼的减少量，l表示当前鱼塘到下一个鱼塘的所需时间
//spend表示鱼塘钓过的次数

int get(int k)
{
    return max(0, a[k] - d[k] * spend[k]); //当前可以钓到的鱼的数量
}

int walk(int n, int T)
{
    int res = 0;
    memset(spend, 0, sizeof(spend));

    for (int i = 0; i < T; i ++ )
    {
        //枚举当前所有的鱼塘，找出当前可以钓到的鱼的数量最多的鱼塘
        int t = 1;
        for (int j = 2; j <= n; j ++ )
            if (get(t) < get(j))
                t = j;

        res += get(t);
        spend[t] ++ ;
    }

    return res;
}

int main()
{
    int n, T;
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &d[i]);
    for (int i = 2; i <= n; i ++ )
    {
        scanf("%d", &l[i]);
        l[i] += l[i - 1];
    }

    scanf("%d", &T);

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        res = max(res, walk(i, T - l[i]));

    printf("%d\n", res);

    return 0;
}