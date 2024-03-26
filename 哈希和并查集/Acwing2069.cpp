#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10010;

int n, m;
int p[N], d[N];

int find(int x)
{
    if (p[x] == x || p[p[x]] == p[x]) return p[x]; //如果x是根节点或者x的父节点是根节点，直接返回x
    int r = find(p[x]);
    d[x] += d[p[x]];
    p[x] = r;
    return r;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    while (m -- )
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (t == 1)
        {
            a = find(a), b = find(b); //找到a和b的祖宗节点
            if (a != b)
            {
                d[a] -= d[b];
                p[a] = b;
            }
        }
        else
        {
            a = find(a);
            d[a] += b;
        }
    }

    for (int i = 1; i <= n; i ++ )
        if (i == find(i)) printf("%d ", d[i]);
        else printf("%d ", d[i] + d[find(i)]);
    puts("");

    return 0;
}