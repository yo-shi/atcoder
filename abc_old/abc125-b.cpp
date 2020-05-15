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
  vector<int> v(n);
  vector<int> p(n);
  REP(i,n){
    int val;cin>>val;
    v[i]=val;
  }
  int sum=0;
  REP(i,n){
    int cost;cin>>cost;
    int pro=v[i]-cost;
    if(pro>0)sum+=pro;
  }
  cout << sum << endl;
}