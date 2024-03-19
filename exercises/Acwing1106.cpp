#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

int n, peak, valley;
int w[N][N];
int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
bool st[N][N];

typedef pair<int, int> PII;

void bfs(int x, int y, bool &has_higher, bool &has_lower)
{
    queue<PII> q;
    q.push({ x, y });
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i ++ )
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a >= 1 && a <= n && b >= 1 && b <= n)
            {
                if (w[a][b] > w[x][y]) has_higher = true;
                if (w[a][b] < w[x][y]) has_lower = true;
                if (w[a][b] == w[x][y] && !st[a][b])
                {
                    q.push({ a, b });
                    st[a][b] = true; //标记已经访问过
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> w[i][j];

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (!st[i][j])
            {
                bool has_higher = false, has_lower = false;
                //如果没有比它高的点，就是山谷，如果没有比它低的点，就是山峰，否则就是山坡
                bfs(i, j, has_higher, has_lower);
                if (!has_higher) peak ++ ;
                if (!has_lower) valley ++ ;
            }

    cout << peak << ' ' << valley << endl;
    return 0;
}