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
  int n,m,c;cin>>n>>m>>c;
  vector<int> b(m);
  REP(i,m){
    cin>>b[i];
  }
  int ans=0;
  REP(i,n){
    int sum=0;
    REP(j,m){
      int a;cin>>a;
      sum+=a*b[j];
    }
    sum+=c;
    if(sum>0){
      ans++;
    }
  }
  cout << ans << endl;
}

