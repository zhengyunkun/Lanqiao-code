#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

// n = a + b / c
// n * c = a * c + b

using namespace std;

const int N = 20;

int n, ans;
bool st[N], backup[N];

bool check(int a, int c)
{
    int b = n * c - a * c;
    memcpy(backup, st, sizeof st); //backup复制于st数组

    while (b)
    {
        int x = b % 10;
        b /= 10;
        if (!x || backup[x]) return false;
        backup[x] = true; //标记b的这一位已经被用过了
    }

    //接下来判断是否所有位都用到过
    for (int i = 1; i <= 9; i ++ )
        if (!backup[i]) 
            return false; //说明有一位没有用到

    return true;
}

void dfs_c(int u, int a, int c) //在a的基础上枚举c
{
    if (u == n) return;

    if (check(a, c)) ans ++ ;

    for (int i = 1; i <= 9; i ++ )
        if(!st[i])
        {
            st[i] = true;
            dfs_c(u + 1, a, c * 10 + i);
            st[i] = false;
        }
}

void dfs_a(int u, int a) //枚举a
{
    if (a >= n) return; //a已经超过n了
    dfs_c(u, a, 0);

    for (int i = 1; i <= 9; i ++ )
        if(!st[i])
        {
            st[i] = true;
            dfs_a(u + 1, a * 10 + i);
            st[i] = false;
        }
}

int main()
{
    cin >> n;

    dfs_a(0, 0);

    cout << ans << endl;

    return 0;
}