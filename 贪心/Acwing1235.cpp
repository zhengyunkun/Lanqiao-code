#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 5e5 + 10;

int n;
int a[N];

int main()
{
    long double s;
    cin >> n >> s;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);

    long double sum = 0;
    long double avg = s / n;

    for (int i = 0; i < n; i ++ )
    {
        long double tmp = s / (n - i);
        if (a[i] < tmp) tmp = a[i];
        sum += (tmp - avg) * (tmp - avg);
        s -= tmp;
    }

    printf(".4Lf\n", sqrt(sum / n));

    return 0;
}