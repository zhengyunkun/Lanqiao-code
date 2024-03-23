#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

typedef long long LL;

int w[N];
int d[N], l[N], r[N];
int n, m;
LL a[N];

bool check(int mid)
{
    for (int i = 1; i <= mid; i ++ )
    {
        a[l[i]] += d[i];
        a[r[i] + 1] -= d[i];
    }

    for (int i = 1; i <= n; i ++ )
    {
        a[i] += a[i - 1];
        if (a[i] > w[i]) return false;
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

    for (int i = 1; i <= m; i ++ ) scanf("%d%d%d", &d[i], &l[i], &r[i]);

    int l = 0, r = m;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid; //因为mid + 1可能不符合条件，所以l = mid
        else r = mid - 1;
    }

    if (r == m) puts("0");
    else printf("-1\n%d\n", r + 1);

    return 0;
}
