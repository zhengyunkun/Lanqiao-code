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

bool dfs(int u, int cur, int start) 
//u是当前枚举到了第几根长木棍，cur是当前已经拼出了多少长度，start是当前从哪根木棍开始拼
{
    if (u * len == sum) return true;
    if (cur == len) return dfs(u + 1, 0, 0);

    for (int i = start; i < n; i ++ )
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