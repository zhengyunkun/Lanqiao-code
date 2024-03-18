#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 50010, M = 999997;

typedef long long LL;

int n, m;
int res;

struct Circle
{
    int x, y, r;
} cir[N];
LL h[N];
int id[M];
bool st[M];

LL get_key(int x, int y)
{
    return x * 1000000001ll + y;
}

int find(int x, int y)
{
    LL key = get_key(x, y);
    int t = (key % M + M) % M;

    while (h[t] != -1 && h[t] != key)
        if ( ++ t == M)
            t = 0;

    return t;
}

int sqr(int x)
{
    return x * x;
}



int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i ++ )
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        cir[i] = { x, y, r };


    }
}