#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

#define all(v) v.begin(), v.end()

const ll mod=1000000007;

ll countBits(ll in){
  int res=0;
  for(;in>0;in>>=1){
    if((in&0x01)!=0){
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

int dfs(vector<vector<int>> &g,int start,int goal,vector<bool>&seen){
  seen[start]=true;
  // cerr<<start<<" : "<<goal<<endl;
  for(auto next: g[start]){
    if(seen[next]){
      continue;
    }
    goal=dfs(g,next,goal+1,seen);
  }
  return goal;
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

ll powm(ll a,ll n, ll m){
  ll ret=1;
  while(n>0){
    if(n%2==1){
      ret=(ret*a)%m;
    }
    n>>=1;
    a=(a*a)%m;
  }
  return ret;
}

void primeFactor(ll val, map<ll,ll> &primeList){
  if(val<1){
    return;
  }
  for(int i=2;i*i<val;i++){
    while(val%i==0){
      primeList[i]++;
      val/=i;
    }
  }
  if(val!=1){
    primeList[val]=1;
  }
  return;
}

const string yesno(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  int n,m;cin>>n>>m;
  vector<vector<int>> g(n+1);
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    if(find(all(g[a]),b)==g[a].end()){
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  int ans=-1;
  vector<bool> seen(n+1,false);
  for(int i=1;i<n+1;i++){
    if(seen[i]){
      continue;
    }
    int res=dfs(g,i,1,seen);
    ans=max(ans,res);
    // cerr<<"------"<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
