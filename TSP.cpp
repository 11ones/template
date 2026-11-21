#include <bits/stdc++.h>
using namespace std;
using L = long long;
using AR = array<L, 2>;

L N, x;
vector<vector<L>> v;
vector<vector<L>> T;

void F(L A, L p) {
  if (!A) {
    if (v[p][0]) T[A][p] = v[p][0];
    return;
  }
  L mn = 2e18;
  for (int i = 1; i < N; ++i) {
    if (!v[p][i]) continue;
    if (A & (1 << i)) {
      L X = A & ~(1 << i);
      if (T[X][i] > 1e18) F(X, i);
      if (T[X][i] < 1e18) mn = min(mn, T[X][i] + v[p][i]);
    }
  }
  if (mn < 1e9) T[A][p] = min(T[A][p], mn);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N;
  v.resize(N, vector<L>(N));
  T.resize(1 << N, vector<L>(N, 2e18));
  for (auto &e : v) for (auto &f : e) cin >> f;
  F((1 << N) - 2, 0);
  cout << T[(1 << N) - 2][0];
}