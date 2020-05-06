#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define REPRl(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < (int)n; i++)
#define FORl(i, m, n) for(ll i = m; i < (ll)n; i++)
#define ALL(v) v.begin(), v.end()
ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
int main() {
  int n;cin>>n;
  int t,a;cin>>t>>a;
  vector<double> hList(n);
  double mn=(double)ULONG_MAX;
  int index=0;
  REP(i,n){
    int x;cin>>x;
    double value=abs((double)t-(double)x*0.006-(double)a);
    if(value<mn){
      mn=value;
      index=i+1;
    }
  }
  cout << index << endl;
}

