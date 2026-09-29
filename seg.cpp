#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ar = array<ll, 2>;

vector<ar> sg;
vector<ll> v;
ar d = {(ll)1e9, -1};

// Build
void B(ll p, ll s, ll e) {
  if (s == e) {
    sg[p] = {v[s], v[s]};
    return;
  }
  ll x = p << 1;
  B(x, s, (s + e) / 2);
  B(x | 1, (s + e) / 2 + 1, e);
  ar l = sg[x];
  ar r = sg[x ^ 1];
  sg[p] = {min(l[0], r[0]), max(l[1], r[1])};
}

// Find
ar F(ll p, ll x, ll y, ll s, ll e) {
  if (y < s || e < x) return d;
  if (x <= s && e <= y) return sg[p];
  ar l = F(p << 1, x, y, s, (s + e) / 2);
  ar r = F(p << 1 | 1, x, y, (s + e) / 2 + 1, e);
  return {min(l[0], r[0]), max(l[1], r[1])};
}

// Update
void U(ll p, ll x, ll s, ll e) {
  if (x < s || e < x) return;
  if (s == e) {
    sg[p] = {v[s], v[s]};
    return;
  }
  if (x <= s && e <= x) return;
  U(p << 1, x, s, (s + e) / 2);
  U(p << 1 ^ 1, x, (s + e) / 2 + 1, e);
  ar l = sg[p << 1];
  ar r = sg[p << 1 ^ 1];
  sg[p] = {min(l[0], r[0]), max(l[1], r[1])};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll N, M, x, y;
  cin >> N >> M;
  v.resize(N);
  sg.resize(4 * N, d);
  for (ll &e : v) cin >> e;
  B(1, 0, N - 1);
  while (M--) {
    cin >> x >> y;
    auto t = F(1, --x, --y, 0, N - 1);
    cout << t[0] << " " << t[1] << "\n";
  }
}

/*
int main() {
  cin.tie(0)->sync_with_stdio(0);
  const long MOD = 1'000'000'007;
  long N, M, K, x, y, z;
  cin >> N >> M >> K;
  M += K;
  vector<long> v(2 * N, 1);
  for (int i = 0; i < N; ++i) cin >> v[N + i];
  for (int i = N - 1; i > 1; --i) v[i] = v[i << 1] * v[i << 1 | 1] % MOD;
  while (M--) {
    cin >> x >> y >> z;
    if (x == 1) {
      for (v[y += N - 1] = z; y > 1; y >>= 1) v[y >> 1] = v[y] * v[y ^ 1] % MOD;
    } else {
      x = 1;
      for (y += N - 1, z += N; y < z; y >>= 1, z >>= 1) {
        if (y & 1) x = x * v[y++] % MOD;
        if (z & 1) x = x * v[--z] % MOD;
      }
      cout << x << '\n';
    }
  }
}
*/