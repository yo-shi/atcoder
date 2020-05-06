#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//#define yskshi
#if defined yskshi
#define debug(s) cout<<s<<endl
#else
#define debug(s)
#endif

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
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}
int main() {
  ull n;cin>>n;
  ull ans=0;
  if(n%2==0){
    if(n>=10){
      for(int i=5,m=10;m<=n;i*=5){
        ans+=n/m;
        m=10*i;
      }
    }
  }
  cout << ans << endl;
}

