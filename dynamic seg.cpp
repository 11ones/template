#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ar = ll;

struct Nd {
  Nd *l = nullptr, *r = nullptr;
  ll x = 0;
};

// Update
void U(Nd* p, ll x, ll y, ll s, ll e) {
  if (y < s || e < x) return;
  if (x <= s && e <= y) {
    p->x = e - s + 1;
    return;
  }
  ll m = (s + e) / 2;
  if (p->l == nullptr) p->l = new Nd();
  if (p->l->x != m - s + 1) U(p->l, x, y, s, m);
  if (p->r == nullptr) p->r = new Nd();
  if (p->r->x != e - m) U(p->r, x, y, m + 1, e);
  ar l = p->l->x;
  ar r = p->r->x;
  p->x = l + r; 
}