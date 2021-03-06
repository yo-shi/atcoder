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
  int n;cin>>n;
  vector<ll> a(n+1);
  for(int i=0;i<n;i++){
    cin>>a[i+1];
  }
  vector<ll> ans(n+1);
  ll x1=0;
  for(int i=0;i<n;i++){
    ll val=a[i+1];
    if(i%2==1){
      val*=(-1);
    }
    x1+=val;
  }
  ans[1]=x1/2;
  for(int i=1;i<n;i++){
    ans[i+1]=a[i]-ans[i];
  }
  for(int i=0;i<n;i++){
    cout<<ans[i+1]*2<<" ";
  }
  cout<<endl;
  return 0;
}
