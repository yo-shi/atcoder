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
  int n;cin>>n;
  multimap<string, pair<int, int> > r;
  set<string> k;
  REP(i,n){
    string s;int p;
    cin>>s>>p;
    r.emplace(s,make_pair(p,i+1));
    k.insert(s);
  }
  for(auto key=k.begin(); key!=k.end(); ++key){
    string city=*key;
    auto list=r.equal_range(city);
    map<int, int, greater<int> > plist;
    for(auto pnt=list.first; pnt!=list.second; ++pnt){
      plist.emplace(pnt->second.first,pnt->second.second);
    }
    for(auto sorted=plist.begin(); sorted!=plist.end(); ++sorted){
      cout<<sorted->second<<endl;
    }
  }
}
