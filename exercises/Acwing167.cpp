#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 70;

int n;
int w[N];
bool st[N];
int sum, len;

bool cmp(int a, int b)
{
    return a > b;
}

bool dfs(int u, int cur, int start) //第u组，cur是第u组当前已有的长度，start表示的是第u组的枚举位置
{
    if (u * len == sum) return true;
    if (cur == len) return dfs(u + 1, 0, 0); //第u组拼完了，开始拼第u + 1组

    for (int i = start; i < n; i ++ )
    {
        if (st[i]) continue;
        if (cur + w[i] <= len)
        {
            st[i] = true;
            if (dfs(u, cur + w[i], i + 1)) return true;
            st[i] = false;
        }

        if (!cur || cur + w[i] == len) return false;

        int j = i + 1;
        while (j < n && w[i] == w[j]) j ++ ;
        i = j - 1;
    }

    return false;
}

int main()
{
    while (cin >> n, n)
    {
        sum = len = 0;
        for (int i = 0; i < n; i ++ )
        {
            cin >> w[i];
            sum += w[i];
            len = max(len, w[i]);
        }

        sort(w, w + n, cmp); //从大到小排序

        memset(st, 0, sizeof st);

        while (true)
        {
            if (sum % len == 0 && dfs(0, 0, 0))
            {
                cout << len << endl;
                break;
            }
            len ++ ;
        }
    }

    return 0;
}