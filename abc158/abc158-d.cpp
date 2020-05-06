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
  string s;cin>>s;
  int q;cin>>q;
  string ans=s;
  bool order=true;
  rep(i,q){
    int t;cin>>t;
    if(t==1){
      order=!order;
    }else{
      int f;cin>>f;
      char c;cin>>c;
      bool begin=false;
      if((f==1&&order)||(f==2&&!order)){
        begin=true;
      }
      if(begin){
        ans.insert(0,1,c);
      }else{
        ans.push_back(c);
      }
    }
  }
  if(!order){
    reverse(ans.begin(),ans.end());
  }
  cout<<ans<<endl;
  return 0;
}

