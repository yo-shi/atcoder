#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

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
  ull n,a,b;cin>>n>>a>>b;
  ull diff=b-a;
  ull ans;
  if((diff%2ULL)==0){
    ans=diff/2ULL;
  }else{
    if(a-1<n-b){
      ans=a-1+1+(b-a-1)/2;
    }else{
      ans=n-b+1+(b-a-1)/2;
    }
  }
  cout << ans << endl;
}

