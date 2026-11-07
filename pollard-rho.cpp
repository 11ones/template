#include <bits/stdc++.h>
using namespace std;
using L = long long;

mt19937_64 rng;

L power(L a, L b, L x) {
  L res = 1, t = 1;
  a %= x;
  do {
    if (b & t) res = (__int128_t)res * a % x;
    a = (__int128_t)a * a % x;
  } while (b >= (t <<= 1));
  return res;
}

L miller(L x) {
  if (x < 2 || x != 2 && !(x % 2)) return 0;
  L t = x - 1, s = 0;
  while (!(1 & t)) t /= 2, ++s;
  vector<L> A = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (auto &e : A) {
    if (x == e) break;
    L y = power(e, t, x);
    if (y == 1 || y == x - 1) continue;
    for (L i = 0; i < s - 1; ++i) {
      y = (__int128_t)y * y % x;
      if (y == 1) {
        return 0;
      }
      if (y == x - 1) {
        goto E;
      }
    }
    return 0;
  E:;
  }
  return 1;
}

L rho(L N) {
  while (1) {
    L c = rng() % (N - 1) + 1;
    L x = rng() % (N - 2) + 2;
    L y = x;
    L d = 1;
    while (d == 1) {
      x = ((__int128_t)x * x + c) % N;
      y = ((__int128_t)y * y + c) % N;
      y = ((__int128_t)y * y + c) % N;
      d = gcd(llabs(x - y), N);
    }
    if (d != N) return d;
  }
}

void factor(L N, vector<L> &v) {
  if (N == 1) return;
  if (!(N % 2)) {
    v.push_back(2);
    factor(N / 2, v);
    return;
  }
  if (miller(N)) {
    v.push_back(N);
    return;
  }
  L d = rho(N);
  factor(d, v);
  factor(N / d, v);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  L T;
  cin >> T;
  while (T--) {
    L x;
    cin >> x;
    vector<L> v;
    factor(x, v);
    sort(v.begin(), v.end());
    cout << v.size() << " ";
    for (auto e : v) cout << e << " ";
    cout << '\n';
  }
}