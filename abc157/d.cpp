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
  rep(i,10){
    int msk=1<<i;
    if((in&msk)!=0){
      res++;
    }
  }
  return res;
}

template<typename T>
void show2dVector(vector<vector<T>>& v){
  rep(i,0){
    int m=v[i].size();
    cout<<i<<" : ";
    rep(j,m){
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

bool dfs(vector<vector<int>> &g,int start,vector<int> &goal,vector<bool>&seen){
  bool res=false;
  seen[start]=true;
  goal.push_back(start);
  for(auto next: g[start]){
    if(seen[next]){
      continue;
    }
    dfs(g,next,goal,seen);
  }
  return res;
}

int main() {
  int n,m,k;cin>>n>>m>>k;
  vector<vector<int>> fri(n);
  vector<vector<int>> blk(n);
  vector<vector<int>> rel(n);
  rep(i,m){
    int a,b;cin>>a>>b;
    a--;b--;
    fri[a].push_back(b);
    fri[b].push_back(a);
    rel[a].push_back(b);
    rel[b].push_back(a);
  }
  cout<<__LINE__<<endl;
  rep(i,k){
    int a,b;cin>>a>>b;
    a--;b--;
    blk[a].push_back(b);
    blk[b].push_back(a);
    rel[a].push_back(b);
    rel[b].push_back(a);
  }
  cout<<__LINE__<<endl;
  vector<vector<int>> conn;
  vector<int> connNum(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<conn.size();j++){
      if(conn[j].end()!=find(all(conn[j]),i)){
        connNum[i]=j;
        continue;
      }
    }
    vector<int> con;
    vector<bool> seen(n,false);
    dfs(fri,i,con,seen);
    connNum[i]=conn.size();
    conn.push_back(con);
  }
  cout<<__LINE__<<endl;
  vector<int> s2(n);
  for(int i=0;i<n;i++){
    vector<int> &bl=blk[i];
    int size2=fri[i].size();
    for(int j=0;j<bl.size();j++){
      if(conn[i].end()!=find(all(conn[i]),bl[j])){
        size2++;
      }
    }
    s2[i]=size2;
  }
  cout<<__LINE__<<endl;
  rep(i,n){
    int ans=conn[connNum[i]].size()-s2[i]-1;
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}
