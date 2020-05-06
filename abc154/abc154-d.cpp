#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reprl(i, n) for(ll i = n; i >= 0; i--)
#define fori(i, m, n) for(int i = m; i < (int)n; i++)
#define forl(i, m, n) for(ll i = m; i < (ll)n; i++)
#define all(v) v.begin(), v.end()
ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}
const string btos(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  ll n,k;cin>>n>>k;
  vector<ll> p(n);
  rep(i,n){
    cin>>p[i];
  }
  auto it=p.begin();
  ll sum=accumulate(it,it+k,0);
  ll ans=sum;
  fori(i,1,n-k+1){
    sum=sum-p[i-1]+p[i+k-1];
    ans=max(ans,sum);
  }
  double an=(double)(ans+k)/2.0;
  cout<< fixed << an << endl;
  return 0;
}

