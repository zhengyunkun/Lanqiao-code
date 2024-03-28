#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;
const int MOD = 1000000007;
LL res;
int m, n, k;
int g[10][110];

int dx2[4] = {-2, -1, 1, 2}; int dy2[4] = {1, 2, 2, 1}; // 只考虑上面的🐎，下面的下面的下面会考虑

string filename = "ans-1.txt";
ofstream out(filename);

void dfs2(int x, int y, int cur)
{
    if(cur == k) 
    {
        res ++;
        res = res % MOD;
        out << "case " << res << ":\n";
        for (int i = 0; i < n; i ++ )
        {
            for (int j = 0; j < n; j ++ )
                out << g[i][j] << " ";
            out << endl;
        }
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

    dfs2(1, 1, 0);

    cout << res;
}