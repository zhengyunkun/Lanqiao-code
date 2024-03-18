#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n;
int ans = N;

struct Edge {
    int id, w;
};

vector<Edge> h[N];

