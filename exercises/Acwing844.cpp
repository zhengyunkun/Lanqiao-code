//bfs模版

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int n, m;
int g[N][N], d[N][N];

void bfs()
{
    queue<PII> q;
    q.push({ 0, 0 });
    memset(d, 0x3f, sizeof d);
    d[0][0] = 0; //起点距离为0

    int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] > d[t.first][t.second] + 1 && !g[x][y])
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({ x, y });
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    bfs();

    cout << d[n - 1][m - 1] << endl;

    return 0;
}