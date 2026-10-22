#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string S, R;
  cin >> S >> R;
  int ls = S.size(), lr = R.size();
  vector<int> k(lr);
  // fail
  int t = 0;
  for (int i = 1; i < lr; i++) {
    while (t && R[t] != R[i]) t = k[--t];
    if (R[t] == R[i]) k[i] = ++t;
    else k[i] = 0;
  }
  // search
  t = 0;
  for (int i = 0; i < ls; i++) {
    while (t && R[t] != S[i]) t = k[t - 1];
    if (R[t] == S[i]) {
      ++t;
      if (t == lr) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}