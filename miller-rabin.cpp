#include <bits/stdc++.h>
using namespace std;
using L = long long;


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
  while (1) {
    if (1 & t) {
      t = t % x;
      break;
    }
    t /= 2;
    ++s;
  }
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  L T;
  cin >> T;
  while (T--) {
    L x;
    cin >> x;
    cout << (miller(x) ? "PRIME\n" : "COMPOSITE\n");
  }
}