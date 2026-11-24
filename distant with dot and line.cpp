#include <bits/stdc++.h>
using namespace std;
using L = long long;
using AR = array<L, 2>;

L Dot(AR A, AR B) { return A[0] * B[0] + A[1] * B[1]; }
L Cross(AR A, AR B) { return A[0] * B[1] - A[1] * B[0];}

AR Dst_dot(AR A, AR B, AR P) {
  AR d = {B[0] - A[0], B[1] - A[1]};
  AR p = {P[0] - A[0], P[1] - A[1]};
  AR bp = {P[0] - B[0], P[1] - B[1]};
  L len = Dot(d, d);
  L dot = Dot(d, p);
  L cross = Cross(d, p);
  if (dot < 0) return {Dot(p, p), 1};
  if (dot >= len) return {Dot(bp, bp), 1};
  return {cross * cross, len};
}

bool num_cmp(AR A, AR B) {
  return A[0] * B[1] <= A[1] * B[0];
}