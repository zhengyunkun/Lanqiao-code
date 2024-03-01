#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

//求1-n的所有子集

using namespace std;

const int N = 16;

int n;
int st[N]; //记录每个位置的状态，0表示没选，1表示选了，2表示不选
vector<vector<int>> ways;

void dfs(int u)
{
    if (u > n)
    {
        vector<int> way;
        for (int i = 1; i <= n; i ++ )
            if (st[i] == 1)
                way.push_back(i);
        ways.push_back(way);
        return;
    }

    st[u] = 2;
    dfs(u + 1);
    st[u] = 0;

    st[u] = 1;
    dfs(u + 1);
    st[u] = 0;
}

int main()
{
    cin >> n;

    dfs(1);

    for (int i = 0; i < ways.size(); i ++ )
    {
        for (int j = 0; j < ways[i].size(); j ++ )
            cout << ways[i][j] << ' ';
        puts("");
    }

    return 0;
}