#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> sg;
vector<int> v;

// Build
void B(int p, int s, int e) {
  if (s == e) {
    sg[p] = {v[s], v[s]};
  } else {
    int x = p << 1;
    B(x, s, (s + e) / 2);
    B(x | 1, (s + e) / 2 + 1, e);
    sg[p] = {min(sg[x][0], sg[x | 1][0]), max(sg[x][1], sg[x | 1][1])};
  }
}

// Find
array<int, 2> F(int p, int x, int y, int s, int e) {
  if (y < s || e < x) return {(int)1e9, 0};
  if (x <= s && e <= y) return sg[p];
  array<int, 2> l = F(p << 1, x, y, s, (s + e) / 2);
  array<int, 2> r = F(p << 1 | 1, x, y, (s + e) / 2 + 1, e);
  return {min(l[0], r[0]), max(l[1], r[1])};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, M, x, y;
  cin >> N >> M;
  v.resize(N);
  sg.resize(4 * N);
  for (int &e : v) cin >> e;
  B(1, 0, N - 1);
  while (M--) {
    cin >> x >> y;
    auto t = F(1, --x, --y, 0, N - 1);
    cout << t[0] << " " << t[1] << "\n";
  }
}