#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> AR;

int CCW(AR A, AR B, AR C) {
  int t = A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - B[0] * A[1] - C[0] * B[1] -
          A[0] * C[1];
  return !t ? 0 : t / t;
}

int Intersect(AR A, AR B, AR C, AR D) {
  if (A > B) swap(A, B);
  if (C > D) swap(C, D);
  int x = CCW(A, B, C) * CCW(A, B, D);
  int y = CCW(C, D, A) * CCW(C, D, B);
  if (!x && !y) return C <= B & A <= D;
  return x <= 0 & y <= 0;
}

int main() {

}