#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

int n;
struct Edge {
    int id, w;
};

vector<Edge> h[N];
int d[N];

void dfs(int u, int father, int distance)
{
    d[u] = distance;
    for (auto e : h[u])
        if (e.id != father)
            dfs(e.id, u, distance + e.w);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        h[a].push_back({b, c});
        h[b].push_back({a, c});
    }

    dfs(1, -1, 0);

    int u = 1;
    for (int i = 1; i <= n; i ++ )
        if (d[i] > d[u])
            u = i;

    memset(d, 0, sizeof d);
    dfs(u, -1, 0);

    for (int i = 1; i <= n; i ++ )
        if (d[i] > d[u])
            u = i;

    int s = d[u];

    printf("%d\n", s * 10 + s * (s + 1) / 2);
    return 0;
}