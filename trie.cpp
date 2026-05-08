#include <bits/stdc++.h>
using namespace std;

struct trie {
  int x;
  int arr[26];
  trie(int x) : x(x) { fill(arr, arr + 26, -1); }
};

int main() {
  string S, s;
  int N, M;
  cin >> N >> S >> M;
  vector<trie> v;
  v.emplace_back(trie(0));
  while (M--) {
    cin >> s;
    auto x = 0;
    for (auto e : s) {
      e -= 'a';
      if (v[x].arr[e] == -1) {
        v.push_back(trie(0));
        v[x].arr[e] = v.size() - 1;
      }
      x = v[x].arr[e];
    }
    v[x].x = 1;
  }
  vector<int> d(N + 1);
  for (int i = 0; i < N; ++i) {
    int x = 0, t = 0;
    while (i + t < N && v[x].arr[S[i + t] - 'a'] != -1) {
      x = v[x].arr[S[i + t] - 'a'];
      ++t;
      d[i + t] += v[x].x;
    }
    d[i + 1] += d[i];
  }
  int c = 0;
  for (auto e : d) c += e;
  cout << c;
}