// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// const int N = 110, M = 1 << 20;


// int n, m, k;
// vector<int> col[N];
// int lg[M];

// int lowbit(int x)
// {
//     return x & -x;
// }

// int h(int state)  // 最少需要再选几行
// {
//     int res = 0;
//     for (int i = (1 << m) - 1 - state; i; i -= lowbit(i))
//     {
//         int c = lg[lowbit(i)];
//         res ++ ;
//         for (auto row : col[c]) i &= ~row;
//     }
//     return res;
// }

// bool dfs(int depth, int state)
// {
//     if (!depth || h(state) > depth) return state == (1 << m) - 1;

//     // 找到选择性最少的一列
//     int t = -1;
//     for (int i = (1 << m) - 1 - state; i; i -= lowbit(i))
//     {
//         int c = lg[lowbit(i)];
//         if (t == -1 || col[t].size() > col[c].size())
//             t = c;
//     }

//     // 枚举选哪行
//     for (auto row : col[t])
//         if (dfs(depth - 1, state | row))
//             return true;

//     return false;
// }

// int main()
// {
//     cin >> n >> m >> k;

//     for (int i = 0; i < m; i ++ ) lg[1 << i] = i;
//     for (int i = 0; i < n; i ++ )
//     {
//         int state = 0;
//         for (int j = 0; j < k; j ++ )
//         {
//             int c;
//             cin >> c;
//             state |= 1 << c - 1;
//         }

//         for (int j = 0; j < m; j ++ )
//             if (state >> j & 1)
//                 col[j].push_back(state);
//     }

//     for (int i = 0; i < m; i ++ )
//     {
//         sort(col[i].begin(), col[i].end());
//         col[i].erase(unique(col[i].begin(), col[i].end()), col[i].end());
//     }


//     int depth = 0;
//     while (depth <= m && !dfs(depth, 0)) depth ++ ;

//     if (depth > m) depth = -1;
//     cout << depth << endl;

//     return 0;
// }

//IDA*做法看不懂喵

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 110, M = 1 << 20, INF = 0x3f3f3f3f;

int n, m, k;
int w[N], dp[M];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= k; j ++ )
        {
            int num;
            cin >> num;
            w[i] |= (1 << (num - 1));
        }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for (int i = 1; i <= n; i ++ )
        for (int s = 0; s < (1 << m); s ++ ) dp[s] = min(dp[s], dp[s & (~w[i])] + 1);

    if (dp[(1 << m) - 1] == INF) cout << -1 << endl;
    else cout << dp[(1 << m) - 1] << endl;

    return 0;
}