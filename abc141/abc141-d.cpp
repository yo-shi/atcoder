#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main() {
  int N,M;
  cin >> N >> M;
  array<long long, 100000> A;
  REP(i,N) {
    cin >> A[i];
  }
  long long sum = 0;
  REP(i,M) {
    int m = 0;
    int idx = 0;
    for (int i = 0; i < N; ++i) {
      if (A[idx] < A[i]) {
        idx = i;
      }
    }
    A[idx] /= 2;
  }
  REP(i,N) {
    sum += A[i];
  }
  cout << sum << endl;
}
