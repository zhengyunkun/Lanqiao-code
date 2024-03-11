#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010, M = 1000000009;

int n, k;
int a[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    sort(a, a + n);

    LL res = 1;
    int l = 0, r = n - 1; //双指针
    int sign = 1; //sign = 1结果为正数

    if(k % 2) //k为奇数
    {
        res = a[r -- ]; //取最大的数字，如果有非负数就选非负数最大的，如果没有选的是最大的负数
        k -- ; //已经选了一个数字

        if (res < 0) sign = -1; //结果必定为负数
    }

    while (k)
    {
        LL x = (LL)a[l] * a[l - 1], y = (LL)a[r] * a[r - 1];
        if (x * sign > y * sign)
        //1.如果sign为1，结果为正数，需要选择尽量大的数，x > y，选择x
        //2.如果sign为-1，结果为负数，需要选择尽量小的数，x > y，选择y
        {
            res = x % M * res % M;
            l += 2;
        }
        else
        {
            res = y % M * res % M;
            r -= 2;
        }

        k -= 2;
    }

    printf("%lld\n", res);

    return 0;
}