#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 10010, INF = 1000000000;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; i ++ ) //定义左端点
    {
        int minv = INF, maxv = - INF;
        for (int j = i; j < n; j ++ ) //定义右端点
        {
            minv = min(minv, a[j]);
            maxv = max(maxv, a[j]);
            if (maxv - minv == j - i) res ++ ;
        }
    }

    cout << res << endl;

    return 0;
}