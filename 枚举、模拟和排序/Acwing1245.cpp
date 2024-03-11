// 弱智题

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 10010;

int n, res;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int x = i;
        while (x)
        {
            int t = x % 10;
            x /= 10;
            if (t == 2 || t == 0 || t == 1 || t == 9)
            {
                res += i;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}