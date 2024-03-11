#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int price[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &price[i]);

    int res = 0;
    for (int i = 0; i + 1 < n; i ++ )
    {
        int dt = price[i + 1] - price[i];
        if (dt > 0)
            res += dt;
    }

    printf("%d\n", res);
    return 0;
}