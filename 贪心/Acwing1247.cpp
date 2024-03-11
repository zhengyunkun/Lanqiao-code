#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int a[N];

int main()
{
    scanf("%d%d", &n, &m);
    int k = m + n + 1;
    for (int i = 0; i < k; i ++ ) scanf("%d", &a[i]);

    LL res = 0;
    if (!m)
    {
        for (int i = 0; i < k; i ++ ) res += a[i];
    }
    else
    {
        sort(a, a + k);
        res = a[k - 1] - a[0];
        for (int i = 0; i < k; i ++ ) res += abs(a[i]);
    }

    printf("%lld\n", res);

    return 0;
}