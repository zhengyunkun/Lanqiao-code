#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;

char g[N][N], backup[N][N];
int dx[5] = { 1, 0, -1, 0, 0 }, dy[5] = { 0, 1, 0, -1, 0 };

void turn(int x, int y)
{
    for (int i = 0; i < 5; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        g[a][b] ^= 1; //异或1
    }
}

int main()
{
    int T;
    cin >> T;

    while (T -- )
    {
        for (int i = 0; i < 5; i ++ ) cin >> g[i];

        //枚举第一行的操作
        int res = 10; //最小操作次数
        for (int op = 0; op < (1 << 5); op ++ )
        //op有5位操作
        {
            memcpy(backup, g, sizeof g);
            int cnt = 0; //记录操作次数
            for (int i = 0; i < 5; i ++ )
                if (op >> i & 1)
                {
                    cnt ++ ;
                    turn(0, i); //把第一行的第i个灯进行操作
                }

            //第一行操作完了，接下来操作后面的灯，
            //因为第一行的操作已经确定，所以后面每行的操作都是确定的
            //由这行推出下一行的操作
            for (int i = 0; i < 4; i ++ )
                for (int j = 0; j < 5; j ++ )
                    if (g[i][j] == '0')
                    {
                        cnt ++ ;
                        turn(i + 1, j);
                    }

            //前四行操作完了，判断最后一行有没有灭的灯
            bool dark = false;
            for (int i = 0; i < 5; i ++ )
                if (g[4][i] == '0')
                {
                    dark = true;
                    break;
                }

            if (!dark) res = min(res, cnt);
            memcpy(g, backup, sizeof g);
        }

        if (res > 6) res = -1;

        cout << res << endl;
    }

    return 0;
}