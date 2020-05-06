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
ll fibonacci(ll n){
  if(n==0){
    return 0;
  }else if(n==1){
    return 1;
  }else{
    return fibonacci(n-1)+fibonacci(n-2);
  }
}

int main() {
  string b;cin>>b;

  REP(i,b.size()){
    if(b[i]=='A'){
      b[i]='T';
    }else if(b[i]=='T'){
      b[i]='A';
    }else if(b[i]=='C'){
      b[i]='G';
    }else{
      b[i]='C';
    }
  }
  cout << b << endl;
}

