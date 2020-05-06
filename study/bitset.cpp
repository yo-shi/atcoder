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
  bitset<4> bs4_15(15);// bs4_15:1111
  cout<<"bs4_15:"<<bs4_15<<endl;
  bitset<8> bs8("00001111");// bs8:00001111
  cout<<"bs8      :"<<bs8<<endl;
  bitset<8> bs8_9("100001111");// bs8_9:10000111
  cout<<"bs8_9    :"<<bs8_9<<endl;

  cout<<"bs8&bs8_9:"<<(bs8&bs8_9)<<endl;
  cout<<"bs8|bs8_9:"<<(bs8|bs8_9)<<endl;
  cout<<"bs8^bs8_9:"<<(bs8^bs8_9)<<endl;
}

