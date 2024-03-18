#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 110;

int n;
int xa, ya, xb, yb;
int dx[4] = { 1, 0, -1, 0}, dy[4] = { 0, 1, 0, -1 };
char g[N][N];
bool st[N][N];

bool dfs(int x, int y)
{
    if (g[x][y] == '#') return false;
    if (x == xb && y == yb) return true;

    st[x][y] = true;
    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;

        if (st[a][b] == true) continue;
        if (dfs(a, b)) return true;
    }

    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> g[i];
        memset(st, false, sizeof st);

        cin >> xa >> ya >> xb >> yb;

        if (dfs(xa, ya)) puts("YES");
        else puts("NO");
    }

    return 0;
}