#include <bits/stdc++.h>
using namespace std;
using L = long long;
using AR = array<L, 2>;

vector<AR> v;

L CCW(AR A, AR B, AR C) {
  return A[0] * B[1] + B[0] * C[1] + C[0] * A[1]
          - B[0] * A[1] - C[0] * B[1] - A[0] * C[1];
}

L D(AR A, AR B) {
  L x = A[0] - B[0];
  L y = A[1] - B[1];
  return x * x + y * y;
}

struct cmp{
  bool operator()(AR A, AR B) {
    L c = CCW(v[0], A, B);
    if (!c) return D(v[0], A) < D(v[0], B);
    return c > 0;
  }
};

L S(vector<AR> s) {
  L c = 0;
  for (int i = 2; i < s.size(); ++i) {
    c += CCW(s[0], s[i - 1], s[i]);
  }
  return c;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  L N;
  cin >> N;
  v.resize(N);
  for (auto &[a, b] : v) cin >> a >> b;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  sort(v.begin() + 1, v.end(), cmp());
  if (v.size() == 1) return cout << "1 0", 0;
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
  cout << s.size() << " " << S(s);
}