#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int x[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> x[i];
    sort(x, x + n);

    int c = x[n / 2];
    LL res = 0;

    for (int i = 0; i < n; i ++ ) res += abs(x[i] - c);
    printf("%lld\n", res);

    return 0;
}