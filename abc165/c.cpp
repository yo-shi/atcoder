#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

#define repr(i, n) for(int i = n; i >= 0; i--)
#define reprl(i, n) for(ll i = n; i >= 0; i--)
#define all(v) v.begin(), v.end()

const ll mod=1000000007;

int countBits(int in){
  int res=0;
  for(int i=0;i<10;i++){
    int msk=1<<i;
    if((in&msk)!=0){
      res++;
    }
  }
  return res;
}

template<typename T>
void show2dVector(vector<vector<T>>& v){
  for(int i=0;i<v.size();i++){
    int m=v[i].size();
    cout<<i<<" : ";
    for(int j=0;i<m;i++){
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
}

void bfs(const vector<vector<int>>&g, int v, vector<bool>& seen){
  seen[v]=true;
  cout<<v<<" ";
  for(auto next: g[v]){
    if(seen[next]){
      continue;
    }
    bfs(g,next,seen);
  }
}

bool dfs(vector<vector<int>> &g,int start,int goal,vector<bool>&seen){
  bool res=false;
  seen[start]=true;
  if(start==goal){
    return true;
  }
  for(auto next: g[start]){
    if(seen[next]){
      continue;
    }
    res=dfs(g,next,goal,seen);
    if(res){
      break;
    }
  }
  return res;
}

ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}
const string outputYesNo(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  int n,m,q;cin>>n>>m>>q;
  vector<int> a(q);
  vector<int> b(q);
  vector<int> c(q);
  vector<int> d(q);
  map<int,vector<int>> query;
  for(int i=0;i<q;i++){
    int a,b,c,d;cin>>a>>b>>c>>d;
    vector<int> s={a,b,c};
    query[d]=s;
  }
  ll ans=0;
  vector<int> seq(n,1);
  vector<bool> cgbit(n,false);
  for(auto it=query.rbegin();it!=query.rend();++it){
    seq[it->second[1]]=seq[it->second[0]]+it->second[2];
    cgbit[it->second[1]]=true;
  }
  for(int i=0;i<m-1;i++){
      for(int j=0;j<n-1;j++){
          ;
      }
  }
  cout<<ans<<endl;
  return 0;
}
