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
  int n;cin>>n;
  map<string,int> s;
  int mx=0;
  rep(i,n){
    string str;cin>>str;
    if(s.find(str)!=s.end()){
      s[str]++;
      mx=max(mx,s[str]);
    }else{
      s[str]=0;
    }
  }
  vector<string> ans;

  for(auto it=s.begin();it!=s.end();++it){
    if(it->second==mx){
      ans.push_back(it->first);
    }
  }
  sort(all(ans));
  for(auto it=ans.begin();it!=ans.end();++it){
    cout<<*it<<endl;
  }
  return 0;
}

