//每个横坐标下有多少星星

#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 32010;

int n;
int tr[N], level[N]; //level表示星星的级数

int lowbit(int x)
{
    return x & -x;
}

void add(int x)
{
    for (int i = x; i < N; i += lowbit(i)) tr[i] ++ ;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x ++ ; // 从1开始

        level[sum(x)] ++ ;
        add(x);
    }

    for (int i = 0; i < n; i ++ ) printf("%d\n", level[i]);

    return 0;
}
