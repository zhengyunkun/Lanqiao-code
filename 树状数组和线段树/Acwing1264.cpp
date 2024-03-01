// 4 = 0 0100
// -4 = 1 0100 -> 1 1011 + 1 -> 1 1100
// 4 & -4 = 0 0100 & 1 1100 = 0 0100 = 4 = 2^2，4末尾有2个0

// 4 + -4 = 0 0100 + 1 1100 = 0 0000 = 0

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int a[N], tr[N];

int main()
{
    
}