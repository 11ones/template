#include <bits/stdc++.h>
using namespace std;

long L(char t) {
  return t - (t >= 'A' ? t >= 'a' ? 'a' - 36 : 'A' - 10 : '0');
}

char C(long t, long B) {
  return t % B + (t % B > 9 ? t % B > 35 ? 'a' - 36 : 'A' - 10 : '0');
}

string baseN(string &S, long A, long B) {
  long c, t;
  string r = "0";
  for (auto &e : S) {
    c = L(e);
    for (long i = 0; i < r.size(); ++i) {
      t = L(r[i]) * A + c;
      r[i] = C(t, B);
      c = t / B;
    }
    while(c) {
      r.push_back(C(c, B));
      c /= B;
    }
  }
  reverse(r.begin(), r.end());
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long A, B;
  string S;
  cin >> A >> B >> S;
  cout << baseN(S, A, B);
}