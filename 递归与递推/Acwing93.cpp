#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int n, m; //从n个数字里面选出m个数字进行排列
int way[N];

void dfs(int u, int start) //当前是第u个位置，从start开始选数字
{
    if (u + n - start < m) return; //剩下的数字不够选
    if (u > m) //已经选了m个数字
    {
        for (int i = 1; i <= m; i ++ ) printf("%d ", way[i]);
        puts("");
        return;
    }

    for (int i = start; i <= n; i ++ )
    {
        way[u] = i;
        dfs(u + 1, i + 1);
        way[u] = 0;
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    dfs(1, 1);

    return 0;
}