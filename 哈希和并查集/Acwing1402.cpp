#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;

const int N = 110, M = 170;
const double eps = 1e-8;

int m, n;
char g[N][N];
PII q[M]; //top表示q数组的元素数量
int top = 0, cnt = 0;
double hash_val[30];

void dfs(int a, int b)
{
    q[top ++ ] = { a, b };
    g[a][b] = '0';

    for (int x = a - 1; x <= a + 1; x ++ )
        for (int y = b - 1; y <= b + 1; y ++ )
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '1')
                dfs(x, y);
}

double get_dist(PII& a, PII& b)
{
    int dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

double get_hash()
{
    double sum = 0;
    for (int i = 0; i < top; i ++ )
        for (int j = i + 1; j < top; j ++ )
            sum += get_dist(q[i], q[j]);
    return sum;
}

char get_id()
{
    double val = get_hash();
    //如果找得到，就返回对应的字母
    for (int i = 0; i < cnt; i ++ )
        if (abs(hash_val[i] - val) < eps)
            return 'a' + i;

    //否则，返回新的字母
    hash_val[cnt ++ ] = val;
    return 'a' + cnt - 1; //cnt ++ 过了，所以这里要减1
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == '1')
            {
                top = 0;
                dfs(i, j);
                char id = get_id(); //得到该星群的标识
                for (int k = 0; k < top; k ++ )
                {
                    int x = q[k].first, y = q[k].second;
                    g[x][y] = id;
                }
            }

    for (int i = 0; i < n; i ++ ) puts(g[i]);

    return 0;
}