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
  vector<int> p(n);
  rep(i,n){
    cin>>p[i];
  }
  vector<int> q(n);
  rep(i,n){
    cin>>q[i];
  }
  vector<int> base(n);
  rep(i,n){
    base[i]=i+1;
  }
  int eqP=-1;
  int eqQ=-1;
  int c=1;
  do{
    if(eqP<0 && equal(all(base),all(p))){
      eqP=c;
    }
    if(eqQ<0 && equal(all(base),all(q))){
      eqQ=c;
    }
    next_permutation(all(base));
    c++;
  }while(eqP<0 || eqQ<0);
  cout << abs(eqP-eqQ) << endl;
  return 0;
}

