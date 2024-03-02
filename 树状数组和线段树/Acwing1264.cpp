// 4 = 0 0100
// -4 = 1 0100 -> 1 1011 + 1 -> 1 1100
// 4 & -4 = 0 0100 & 1 1100 = 0 0100 = 4 = 2^2，4末尾有2个0

// 4 + -4 = 0 0100 + 1 1100 = 0 0000 = 0

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int a[N], tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) add(i, a[i]);

    while (m -- )
    {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);

        if (k == 0) printf("%d\n", query(y) - query(x - 1));
        else add(x, y);
    }

    return 0;
}