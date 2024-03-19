#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 110;

int n, m, T;
char mp[N][N];
bool st[N][N];

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y)
{
    st[x][y] = true;

    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && mp[a][b] == '1' && !st[a][b]) dfs(a, b);
    }
}

int main()
{
    cin >> T;
    for (int c = 1; c <= T; c ++ )
    {
        cin >> n >> m;
        for (int i = 0; i < n; i ++ ) cin >> mp[i];

        int op; 
        cin >> op;

        printf("Case #%d:\n", c);
        while (op -- )
        {
            char ch;
            int res = 0;

            cin >> ch;
            if (ch == 'M')
            {
                int a, b, c;
                cin >> a >> b >> c;
                mp[a][b] = '0' + c;
            }
            else
            {
                memset(st, 0, sizeof st);
                for (int i = 0; i < n; i ++ )
                    for (int j = 0; j < m; j ++ )
                        if (mp[i][j] == '1' && !st[i][j]) //!st[i][j]是为了防止重复遍历点
                        {
                            dfs(i, j);
                            res ++ ;
                        }
                cout << res << endl;
            }
        }
    }

    return 0;
}