#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1010;

int n, h, r;
struct Sphere
{
    int x, y, z;
} q[N]; // q[i]表示第i个球球心的坐标
int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x]; // 返回x的祖宗节点
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d%d%d", &n, &h, &r);
        for (int i = 1; i <= n; i ++ )
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            q[i] = { a, b, c };
        }
    }

}

