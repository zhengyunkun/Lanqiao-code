#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

//求出每个节点到根结点的距离
void dfs(int u, int father, int distance)
{
    dist[u] = distance;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i]; //j是u的儿子
        if (j != father) dfs(j, u, distance + w[i]);
    }
}

int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1, 0);

    int u = 1;
    for (int i = 1; i <= n; i ++ )
        if (dist[i] > dist[u])
            u = i; //找到距离根结点最远的点

    memset(dist, 0, sizeof dist);

    dfs(u, -1, 0);

    for (int i = 1; i <= n; i ++ )
        if (dist[i] > dist[u])
            u = i; //找到距离根结点最远的点

    int ans = dist[u];

    printf("%lld\n", ans * 10 + ans * (ans + 1ll) / 2);

    return 0;
}