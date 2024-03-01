#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

//求1-n的全排列

using namespace std;

const int N = 10;

int n;
int st[N]; //0表示还没放数字，1-n表示放哪一个数字
bool used[N]; //记录数字是否被用过

void dfs(int u) //第u个位置
{
    if (u > n)
    {
        for (int i = 1; i <= n; i ++ ) cout << st[i] << ' ';
        puts("");

        return;
    }

    //依次枚举每一个分支
    for (int i = 1; i <= n; i ++ )
        if (!used[i])
        {
            st[u] = i;
            used[i] = true;
            dfs(u + 1);

            st[u] = 0;
            used[i] = false;
        }
}

int main()
{
    cin >> n;

    dfs(1); //从第一个位置开始放数字

    return 0;
}