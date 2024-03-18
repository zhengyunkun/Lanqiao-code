#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ; //头插法
}

int dfs(int u, int father)
{
    int sum = 0;
    int maxv = 0;
    for (int i = h[u]; ~i; i = ne[i]) //-1的二进制补码为11111111 11111111 11111111 11111111
    {
        int j = e[i]; //j是u的儿子
        if (j != father)
        {
            int t = dfs(j, u);
            sum += t;
            maxv = max(maxv, t);
        }
    }

    maxv = max(maxv, n - sum - 1);
    ans = min(ans, maxv);
    return sum + 1;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1, -1);
    cout << ans << endl;
    return 0;
}