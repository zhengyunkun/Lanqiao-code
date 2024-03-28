#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
const int MOD = 1000000007;
LL res;
int m, n, k;
int g[10][110];
int base1[3000][10][110];
int base2[3000][10][110];
int dx2[4] = {-2, -1, 1, 2}; int dy2[4] = {1, 2, 2, 1}; // 只考虑上面的🐎，下面的下面的下面会考虑
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs1(int x, int y, int cur)
{
    if(cur == k) 
    {
        res ++;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                base1[res][i][j] = g[i][j];
        res = res % MOD;
        return ;
    }

    if(y > m) y = 1, x ++ ;
    if(x > n) return ;


    dfs1(x, y + 1, cur);

    int flag = 1;
    for(int j = 0; j < 8; j ++) // 检查和之前的🐎是否冲突
    {
        int a = x + dx[j], b = y + dy[j];
        if(a >= 0 && a <= n && b >= 0 && b <= m)
            if(g[a][b])
            {
                flag = 0;  
                break;
            }
    }
    // 对于不冲突的🐎
    if(flag) 
    {
        g[x][y] = 1;
        dfs1(x, y + 1, cur + 1);
        g[x][y] = 0;    
    }
}

void dfs2(int x, int y, int cur)
{
    if(cur == k) 
    {
        res ++;
        res = res % MOD;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                base2[res][i][j] = g[i][j];
        return ;
    }

    if(y > m) y = 1, x ++ ;
    if(x > n) return ;


    dfs2(x, y + 1, cur);

    int flag = 1;
    for(int j = 0; j < 4; j ++) // 检查和之前的🐎是否冲突
    {
        int a = x + dx2[j], b = y + dy2[j];
        if(a >= 0 && a <= n && b >= 0 && b <= m)
            if(g[a][b])
            {
                flag = 0;  
                break;
            }
    }
    // 对于不冲突的🐎
    if(flag) 
    {
        g[x][y] = 1;
        dfs2(x, y + 1, cur + 1);
        g[x][y] = 0;    
    }
}

int main()
{
    cin >> n >> m >> k;

    dfs1(1, 1, 0);
    memset(g, 0, sizeof g);
    res = 0;
    dfs2(1, 1, 0);

    for(int i = 1; i <= res; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            for(int k = 0; k < m; k ++)
            {
                if (base1[i][j][k] != base2[i][j][k])
                {
                    for (int i = 0; i < n; i ++ )
                    {
                        cout << "base1:" << endl;
                        for (int i = 0; i < n; i ++ )
                        {
                            for (int j = 0; j < n; j ++ )
                                cout << base2[res][i][j] << " ";
                            cout << endl;
                        }
                        cout << "base2:" << endl;
                        for (int i = 0; i < n; i ++ )
                        {
                            for (int j = 0; j < n; j ++ )
                                cout << base2[res][i][j] << " ";
                            cout << endl;
                        }
                    }
                    return 0;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << res;
}