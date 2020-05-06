#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPul(i, n) for (ull i = 0; i < (ull)(n); i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define REPRl(i, n) for(ll i = n; i >= 0; i--)
#define REPRul(i, n) for(ull i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < (int)n; i++)
#define FORl(i, m, n) for(ll i = m; i < (ll)n; i++)
#define FORul(i, m, n) for(ull i = m; i < (ull)n; i++)
#define ALL(v) v.begin(), v.end()
ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
ull fibonacci(ull n){
  ull bb=1,b=1;
  if(n==0){
    return 0;
  }else if(n==1){
    return bb;
  }else if(n==2){
    return b;
  }
  ull f=bb+b;
  REPl(i,n-2){
    f=bb+b;
    f%=1000000007;
    bb=b;
    b=f;
  }
  return f;
}

int main() {
  int n,m;cin>>n>>m;
  vector<ull> a(m+1);
  REPl(i,m){
    ull b;cin>>b;
    a[i]=b;
  }
  a[m]=n+1;
  vector<ull> p(m+1);
  p[0]=fibonacci(a[0]);
  FORl(i,1,m+1){
    p[i]=fibonacci(a[i]-a[i-1]-1);
  }
  ull ans=1;
  REPl(i,m+1){
    ans*=p[i];
  }
  ans%=1000000007;
  cout << ans << endl;
}

