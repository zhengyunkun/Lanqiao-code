#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1010;

char g[N][N];
bool st[N][N];
int flag;
int n, ans;

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y)
{
    st[x][y] = true;

    //判断是否有不会被淹没的点
    if (g[x - 1][y] == '#' && g[x + 1][y] == '#' && g[x][y - 1] == '#' && g[x][y + 1] == '#') 
        flag = 1; //岛不会被淹没

    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a > 0 && a <= n && b > 0 && b <= n && g[a][b] == '#' && !st[a][b])
            dfs(a, b);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

    //第一次dfs求出原先的连通块数量
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (g[i][j] == '#' && !st[i][j])
            {
                flag = 0;
                dfs(i, j);
                if (!flag) ans ++ ;
            }

    printf("%d\n", ans);

    return 0;
}