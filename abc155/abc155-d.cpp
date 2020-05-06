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
  vector<ll> a(n);
  repl(i,n){
    cin>>a[i];
  }
  map<ll,ll> ans;
  repl(i,n-1)forl(j,i+1,n){
    ll val=a[i]*a[j];
    if(ans.find(val)!=ans.end()){
      ans[val]++;
    }else{
      ans[val]=1;
    }
  }
  ll c=0;
  ll answer=0;
  for(auto it=ans.begin();it!=ans.end();++it){
    c+=it->second;
    if(c>=k){
      answer=it->first;
      break;
    }
  }
  cout << answer<<endl;
  return 0;
}

