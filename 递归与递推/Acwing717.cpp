#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//非递归算法

// long long n, a, b = 1, c;

//输出前n项的斐波那契数列

// int main()
// {
//     scanf("%lld", &n);
    
//     while (n -- )
//     {
//         printf("%lld ", a);
//         c = a + b;
//         a = b, b = c;
//     }
    
//     return 0;
// }

//递归算法

int n;
int q[100];

int f(int n)
{
    if (n == 1) q[1] = 0;
    if (n == 2) q[2] = 1;
    
    q[1] = 0, q[2] = 1;
    for (int i = 3; i <= n; i ++ )
    {
        int x = f(i - 1) + f(i - 2);
        q[i] = x;
    }

    return q[n];
}

int main()
{
    cin >> n;
    f(n);

    for (int i = 1; i <= n; i ++ ) cout << q[i] << ' ';

    return 0;
}