#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    
    int l, r, c;
    while(m -- )
    {
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    
    for(int i = 1; i <= n; i ++ )
    {
        a[i] = b[i] + a[i - 1];
        cout << a[i] << ' ';
    }
    
    return 0;
}