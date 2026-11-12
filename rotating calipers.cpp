#include <bits/stdc++.h>
using namespace std;
using L = long long;
using AR = array<L, 2>;

vector<AR> v;

L CCW(AR A, AR B, AR C) {
  return A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - B[0] * A[1] - C[0] * B[1] -
         A[0] * C[1];
}

L CCW(AR A, AR B, AR C, AR D) {
  D[0] -= (C[0] - B[0]);
  D[1] -= (C[1] - B[1]);
  return CCW(A, B, D);
}

L D(AR A, AR B) {
  L x = A[0] - B[0];
  L y = A[1] - B[1];
  return x * x + y * y;
}

struct cmp {
  bool operator()(AR A, AR B) {
    L c = CCW(v[0], A, B);
    if (!c) return D(v[0], A) < D(v[0], B);
    return c > 0;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  L N;
  cin >> N;
  v.resize(N);
  for (auto &[a, b] : v) cin >> a >> b;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  sort(v.begin() + 1, v.end(), cmp());
  if (v.size() == 1) return cout << 0, 0;
  vector<AR> s = {v[0], v[1]};
  L p = 1;
  for (int i = 2; i < v.size(); ++i) {
    while (p > 0) {
      if (CCW(s[p - 1], s[p], v[i]) <= 0) {
        s.pop_back();
        --p;
        continue;
      }
      break;
    }
    s.push_back(v[i]);
    ++p;
  }
  L ls = s.size(), r = 1, d = -1, a = -1, b = -1;
  if (ls == 1) return cout << 0, 0;
  if (ls == 2) return cout << D(s[0], s[1]), 0;
  for (int l = 0; l < s.size(); ++l) {
    while (CCW(s[l], s[(l + 1) % ls], s[r % ls], s[(r + 1) % ls]) > 0) {
      if (D(s[l], s[r % ls]) > d) {
        d = D(s[l], s[r % ls]);
        a = l;
        b = r;
      }
      ++r;
    }
    if (D(s[l], s[r % ls]) > d) {
      d = D(s[l], s[r % ls]);
      a = l;
      b = r;
    }
  }
  cout << d;
}