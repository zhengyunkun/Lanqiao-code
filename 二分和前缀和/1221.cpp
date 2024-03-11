#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 5e6 + 10;

int n;

//暴力n^3

// int main()
// {
//     cin >> n;
//     for (int a = 0; a * a <= n; a ++ )
//         for (int b = a; a * a + b * b <= n; b ++ )
//             for (int c = b; a * a + b * b + c * c <= n; c ++ )
//             {
//                 int t = n - a * a - b * b - c * c;
//                 int d = sqrt(t);
//                 if (d * d == t)
//                 {
//                     printf("%d %d %d %d\n", a, b, c, d);
//                     return 0;
//                 }
//             }
// }

//二分做法

struct Sum
{
    int s, c, d;
    bool operator< (const Sum &t) const
    {
        if (s != t.s) return s < t.s;
        if (c != t.c) return c < t.c;
        return d < t.d;
    }
} sum[N];

bool cmp(Sum a, Sum b)
{
    if (a.s != b.s) return a.s < b.s;
    if (a.c != b.c) return a.c < b.c;
    return a.d < b.d;
}

int n, m;

int main()
{
    cin >> n;

    for (int c = 0; c * c <= n; c ++ )
        for (int d = c; c * c + d * d <= n; d ++ )
            sum[m ++ ] = { c * c + d * d, c, d };

    sort(sum, sum + m, cmp);

    for (int a = 0; a * a <= n; a ++ )
        for (int b = a; b * b + a * a <= n; b ++ )
        {
            int t = n - a * a - b * b;
            int l = 0, r = m - 1;

            while (l < r)
            {
                int mid = l + r >> 1;
                if (sum[mid].s >= t) r = mid;
                else l = mid + 1;
            }

            if (sum[l].s == t)
            {
                printf("%d %d %d %d\n", a, b, sum[l].c, sum[l].d);
                return 0;
            }
        }

    return 0;
}

//哈希做法

