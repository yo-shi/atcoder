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
int countBits(int in){
  int res=0;
  for(int i=0;i<15;i++){
    int msk=1<<i;
    if((in&msk)!=0){
      res++;
    }
  }
  return res;
}
int main() {
  int n;cin>>n;
  vector<vector<P>> in(n);
  rep(i,n){
    int a;cin>>a;
    vector<P> alist(a);
    rep(j,a){
      P xy;
      cin>>xy.first>>xy.second;
      xy.first--;
      xy.second;
      alist[j]=xy;
    }
    in[i]=alist;
  }
  int ans=0;
  rep(i,1<<n){// Honest or Unkindの全パターン
    bool checker=true;
    rep(j,n){// N人の証言をチェック
      int ish=(i>>j)&0x01;
      if(!ish){// パターンiでHonestの証言だけ見る
        continue;
      }
      rep(k,in[j].size()){// jさんの証言を全て見る
        int person=in[j][k].first;
        int HorU=in[j][k].second;
        if(((i>>person)&0x01)==HorU){//jさんのpersonに関する証言がiと一致していればOK
          continue;
        }
        // 一致していなければ
        checker=false;
        break;
      }
      if(!checker){
        break;
      }
    }
    if(checker){
      int cnt=countBits(i);
      ans=max(ans,cnt);
    }
  }
  cout << ans << endl;
  return 0;
}

