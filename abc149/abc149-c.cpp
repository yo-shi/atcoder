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
vector<int> p(10000);
bool isPrime(int a){
  if(a<2){
    return false;
  }
  if(a==2){
    return true;
  }
  for(int i=3;i<a;i+=2){
    if(a%i==0){
      return false;
    }
  }
  return true;
}
int main() {
  int x;cin>>x;
  int ans;
  if(x==2){
    cout << x << endl;
    return 0;
  }
  p[0]=2;
  int j=1;
  for(int i=3;i<x;i+=2){
    if(isPrime(i)){
      p[j]=i;
    }
  }
  ans=(x%2==0)?x+1:x;
  while(true){
    if(isPrime(ans)){
      break;
    }
    ans+=2;
  }
  cout << ans << endl;
}

