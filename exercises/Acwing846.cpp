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
    int sum = 0;
    int maxv = 0;
    for (auto e : h[u])
        if (e.id != father)
        {
            int t = dfs(e.id, u);
            sum += t;
            maxv = max(maxv, t);
        }

    maxv = max(maxv, n - sum - 1);

    ans = min(ans, maxv);
    
    return sum + 1; //返回以u为根的子树的节点数
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

    dfs(1, -1); //以1为根的子树的节点数
    cout << ans << endl;
    return 0;
}