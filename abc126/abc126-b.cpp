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
  string s;cin>>s;
  int l=stoi(s.substr(0,2));
  int r=stoi(s.substr(2));
  bool mmyy=false,yymm=false;
  bool isValid=true;
  if(0<l&&l<=12){
    mmyy=true;
  }else{
    mmyy=false;
    if(0==r||12<r){
      isValid=false;
    }
  }
  if(0<r&&r<=12){
    yymm=true;
  }else{
    yymm=false;
    if(0==l||12<l){
      isValid=false;
    }
  }
  string ans;
  if(!isValid){
    ans="NA";
  }else if(yymm && mmyy){
    ans="AMBIGUOUS";
  }else if(yymm){
    ans="YYMM";
  }else if(mmyy){
    ans="MMYY";
  }
  cout << ans << endl;
}

