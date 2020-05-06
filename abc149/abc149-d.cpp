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
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}
int main() {
  int n,k;cin>>n>>k;
  int r,s,p;cin>>r>>s>>p;
  string tt;cin>>tt;
  string t=string(tt);
  REP(i,n){
    if(t[i]=='r'){
      t[i]='p';
    }else if(t[i]=='s'){
      t[i]='r';
    }else if(t[i]=='p'){
      t[i]='s';
    }
  }
  FOR(i,k,n){
    if(t[i-k]==t[i]){
      if(t[i]=='p'){
        if(i>=n-k){
          t[i]='r';
          continue;
        }
        if(t[i+k]=='r'){
          t[i]='s';
        }else if(t[i+k]=='s'){
          t[i]='r';
        }else{
          t[i]='r';
        }
      }else if(t[i]=='r'){
        if(i>=n-k){
          t[i]='p';
          continue;
        }
        if(t[i+k]=='p'){
          t[i]='s';
        }else if(t[i+k]=='s'){
          t[i]='p';
        }else{
          t[i]='p';
        }
      }else if(t[i]=='s'){
        if(i>=n-k){
          t[i]='p';
          continue;
        }
        if(t[i+k]=='r'){
          t[i]='p';
        }else if(t[i+k]=='p'){
          t[i]='r';
        }else{
          t[i]='p';
        }
      }
    }
  }
  int ans=0;
  REP(i,n){
    if(t[i]=='r'&&tt[i]=='s'){
      ans+=r;
    }
    if(t[i]=='p'&&tt[i]=='r'){
      ans+=p;
    }
    if(t[i]=='s'&&tt[i]=='p'){
      ans+=s;
    }
  }
  cout << ans << endl;
}

