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

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx2[4] = {-2, -1, 1, 2}, dy2[4] = {1, 2, 2, 1};

string filename = "ans.txt";
ofstream out(filename);

void dfs1(int x, int y, int cur)
{
    if(cur == k) 
    {
        res ++;
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

int main()
{
    cin >> n >> m >> k;

    dfs1(1, 1, 0);

    cout << res;
}