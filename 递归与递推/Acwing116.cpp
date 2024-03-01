#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define x first;
#define y second;

typedef pair<int, int> PII;

const int N = 10;

char g[N][N], backup[N][N];

int get(int a, int b)
{
    return 4 * a + b;
}

void turn_one(int a, int b)
{
    if (g[a][b] == '+') g[a][b] = '-';
    else g[a][b] = '+';
}

void turn_all(int a, int b)
{
    for (int i = 0; i < 4; i ++ )
    {
        turn_one(a, i);
        turn_one(i, b);
    }

    turn_one(a, b);
}

int main()
{
    for (int i = 0; i < 4; i ++ ) cin >> g[i];

    vector<PII> res; //初始时为空
    for (int op = 0; op < (1 << 16); op ++ )
    {
        vector<PII> temp;

        memcpy(backup, g, sizeof g);

        for (int i = 0; i < 4; i ++ )
            for (int j = 0; j < 4; j ++ )
            {
                if (op >> get(i, j) & 1)
                {
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
            }

        //检查是否所有的门把手都打开了
        bool has_closed = false;
        for (int i = 0; i < 4; i ++ )
            for (int j = 0; j < 4; j ++ )
                if (g[i][j] == '+')
                    has_closed = true;

        if (!has_closed)
        {
            if (res.empty() || temp.size() < res.size()) res = temp;
        }

        memcpy(g, backup, sizeof g); //恢复g数组
    }

    cout << res.size() << endl;
    for (auto& p : res) cout << p.first + 1 << ' ' << p.second + 1 << endl;

    return 0;
}