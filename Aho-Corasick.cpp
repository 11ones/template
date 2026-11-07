#include <bits/stdc++.h>
using namespace std;

struct trie {
  int x;
  int arr[26];
  int fail = 0;
  int r = 0;
  trie(int x) : x(x) { fill(arr, arr + 26, -1); }
};

int main() {
  int N, M;
  cin >> M;
  vector<trie> v;
  vector<string> S(M);
  for (auto &e : S) cin >> e;
  v.emplace_back(trie(0));
  for (auto &s : S) {
    int x = 0;
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
  queue<int> q;
  vector<int> st;
  for (int i = 0; i < 26; ++i) if(v[0].arr[i] != -1) q.push(v[0].arr[i]);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    st.push_back(t);
    for (int i = 0; i < 26; ++i) {
      int c = v[t].arr[i];
      if (c == -1) continue;
      int p = v[t].fail;
      while (p && v[p].arr[i] == -1) p = v[p].fail;
      if (v[p].arr[i] != -1) p = v[p].arr[i];
      v[c].fail = p;
      // if (v[p].x) v[c].x = 1;
      q.push(c);
    }
  }
  string s;
  cin >> s;
  int l = s.size(), x = 0;
  for (auto e : s) {
    while (x && v[x].arr[e - 'a'] == -1) x = v[x].fail;
    if (v[x].arr[e - 'a'] != -1) x = v[x].arr[e - 'a'];
    ++v[x].r;
  }
  reverse(st.begin(), st.end());
  for (auto e : st) {
    v[v[e].fail].r += v[e].r;
  }
  for (auto &e : S) {
    int x = 0;
    for (auto &f : e) {
      x = v[x].arr[f - 'a'];  
    }
    cout << v[x].r << " ";
  }
}