#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n;
int ans = N;

struct Edge {
    int id;
};

vector<Edge> h[N];

int dfs(int u, int father)
{
    int res = 0, sum = 0;
    for (auto e : h[u])
        if (e.id != father)
        {
            int t = dfs(e.id, u);
            res = max(res, t);
            sum += t;
        }

    res = max(res, n - sum - 1);
    ans = min(ans, res);
    return sum + 1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        h[a].push_back({b});
        h[b].push_back({a});
    }

    dfs(1, -1);
    cout << ans << endl;
    return 0;
}