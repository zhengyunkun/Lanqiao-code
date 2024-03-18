// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>

// #define x first
// #define y second

// using namespace std;

// typedef pair<int, int> PII;

// const int N = 55;

// int n, m;
// char g[N][N];
// vector<PII> points[2];

// int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

// void dfs(int x, int y, vector<PII> &ps)
// {
//     g[x][y] = '.';
//     ps.push_back({x, y});

//     for (int i = 0; i < 4; i ++ )
//     {
//         int a = x + dx[i], b = y + dy[i];
//         if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 'X') dfs(a, b, ps);
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i ++ ) cin >> g[i];

//     for (int i = 0, k = 0; i < n; i ++ )
//         for (int j = 0; j < m; j ++ )
//             if (g[i][j] == 'X')
//                 dfs(i, j, points[k ++ ]);

//     int res = 1e8;
//     for (auto& a : points[0])
//         for (auto& b : points[1])
//             res = min(res, abs(a.x - b.x) + abs(a.y - b.y) - 1); //减去1才为需要涂的数量

//     cout << res << endl;

//     return 0;
// }