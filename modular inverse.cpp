#include <bits/stdc++.h>
using namespace std;

const long MOD = 998244353;
vector<int> f;

long power(long a, long b) {
  long res = 1, t = 1;
  a %= MOD;
  do {
    if (b & t) res = (res * a) % MOD;
    a = (a * a) % MOD;
  } while (b >= (t <<= 1));
  return res;
}

long mi(long n) { return power(n, MOD - 2); }

long comb_c(long n, long r) { return f[n] * mi(f[n - r]) % MOD * mi(f[r]) % MOD; }
long comb_h(long n, long r) { return comb_c(n + r - 1, r); }

/*
// 분할 정복을 이용한 거듭제곱 (a^b % mod)
long long power(long long a, long long b, long long mod) {
    long long res = 1, t = 1;
    a %= mod;
    do {
         if (b & t) res = (res * a) % mod;
        a = (a * a) % mod;
    } while (b >= (t <<= 1));
    return res;
}

// 모듈러 역원 계산 (M이 소수일 때)
long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}
*/

int main() {
    const long MOD = 998244353;
    long a, b;
    cin >> a >> b;
    cout << a * mi(b);
}