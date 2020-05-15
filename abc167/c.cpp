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
  int n,m,x;cin>>n>>m>>x;
  vector<int> c(n);
  vector<vector<int>> a(n,vector<int>(m));
  for(int i=0;i<n;i++){
    cin>>c[i];
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  ll ans=LLONG_MAX;
  int cnt=0;
  int mx=pow(2,n);
  for(int cnt=0;cnt<mx;cnt++){
    vector<int> sum(n,0);
    ll cost=0;
    for(int i=0;i<n;i++){
      if(((cnt>>i)&0x01)==0){
        continue;
      }
      cost+=c[i];
      for(int j=0;j<m;j++){
        sum[j]+=a[i][j];
      }
    }
    bool checker=true;
    for(int j=0;j<m;j++){
      if(sum[j]<x){
        checker=false;
        break;
      }
    }
    if(checker){
      ans=min(ans,cost);
    }
  }
  if(ans==LLONG_MAX){
    ans=-1;
  }
  cout<<ans<<endl;
  return 0;
}
