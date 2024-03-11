#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100010;

int n;
int a[N], b[N], c[N];
int as[N]; //as[i]表示a[N]中多少个数小于b[i]
int cs[N]; //cs[i]表示c[N]中多少个数大于b[i]
int cnt[N], s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]), a[i] ++ ;
    for (int i = 0; i < n; i ++ ) scanf("%d", &b[i]), b[i] ++ ;
    for (int i = 0; i < n; i ++ ) scanf("%d", &c[i]), c[i] ++ ;

    //求as[i]
    for (int i = 0; i < n; i ++ ) cnt[a[i]] ++ ;
    for (int i = 1; i <= N; i ++ ) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i ++ ) as[i] = s[b[i] - 1];

    //求cs[i]
    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);

    for (int i = 0; i < n; i ++ ) cnt[c[i]] ++ ;
    for (int i = N; i; i -- ) s[i] = s[i + 1] + cnt[i];
    for (int i = 0; i < n; i ++ ) cs[i] = s[N - 1] - s[b[i] + 1];

    long long res = 0;
    for (int i = 0; i < n; i ++ ) res += (long long)as[i] * cs[i];
    printf("%lld\n", res);

    return 0;
}