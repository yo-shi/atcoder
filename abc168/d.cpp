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

void bfs(const vector<vector<int>>&g, int v, int p, vector<int> &checker, vector<bool>& seen){
  seen[v]=true;
  checker[v]=p;
  cout<<v<<" : "<<p<<endl;
  queue<int> q;
  for(auto next: g[v]){
    if(seen[next]){
      continue;
    }
    bfs(g,next,v,checker,seen);
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

const string yesno(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  int n,m;cin>>n>>m;
  vector<vector<int>> g(n);
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> ans(n);
  vector<bool> seen(n,false);
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int val=q.front();q.pop();
    for(int i:g[val]){
      if(seen[i]){
        continue;
      }
      ans[i]=val;
      q.push(i);
      seen[i]=true;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=1;i<n;i++){
    cout<<ans[i]+1<<endl;
  }
  return 0;
}
