#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 310;

int n;
char mp[N][N];
int cnt[N][N]; //统计雷的数量

int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }, dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int x, int y)
{
    int t = cnt[x][y];
    cnt[x][y] = -1; //已经访问过这个点，不再访问

    if (t) return; //如果这个点附近有雷，就不再继续搜索
    else
    {
        for (int i = 0; i < 8; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < n && cnt[a][b] != -1) dfs(a, b);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k ++ )
    {
        int ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) scanf("%s", mp[i]);

        memset(cnt, 0, sizeof cnt);
        //统计九宫格内雷的数量
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                if (mp[i][j] == '*') cnt[i][j] = -1; //无法访问的雷
                else
                {
                    for (int c = 0; c < 8; c ++ )
                    {
                        int x = i + dx[c], y = j + dy[c];
                        if (x >= 0 && x < n && y >= 0 && y < n && mp[x][y] == '*') 
                            cnt[i][j] ++ ;
                    }
                }

        //dfs寻找联通块
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                if (cnt[i][j] == 0) //如果当前点没有雷，会把周围8格的情况都找一遍
                {
                    dfs(i, j);
                    ans ++ ;//搜索完一个联通块
                }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                if (cnt[i][j] != -1) ans ++ ;

        printf("Case #%d: %d", k, ans);
    }
}