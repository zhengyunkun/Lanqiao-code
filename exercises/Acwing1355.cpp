#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 21, M = N * N * N;

int A, B, C;
bool st[N][N][N];

void dfs(int a, int b, int c)
{
    if (st[a][b][c]) return;
    st[a][b][c] = true;
    dfs(a - min(a, B - b), b + min(a, B - b), c);
    dfs(a - min(a, C - c), b, c + min(a, C - c));
    dfs(a + min(b, A - a), b - min(b, A - a), c);
    dfs(a, b - min(b, C - c), c + min(b, C - c));
    dfs(a + min(c, A - a), b, c - min(c, A - a));
    dfs(a, b + min(c, B - b), c - min(c, B - b));
}

int main()
{
    scanf("%d%d%d", &A, &B, &C);
    dfs(0, 0, C);

    for (int c = 0; c <= C; c ++ )
        for (int b = 0; b <= B; b ++ )
            if (st[0][b][c])
            {
                cout << c << ' ';
                break; //当前c已经存在，不需要继续枚举下去
            }

    return 0;
}