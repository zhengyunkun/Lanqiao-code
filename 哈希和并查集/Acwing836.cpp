#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) p[i] = i; //初始化并查集

    while (m -- )
    {
        char ch;
        scanf("%s", &ch);
        if (ch == 'M')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            p[find(a)] = p[find(b)];
        }
        else
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}