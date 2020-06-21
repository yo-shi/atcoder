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
  int x,y;cin>>x>>y;
  int a,b;
  if((y-2*x)%2==0){
    b=(y-2*x)/2;
    if(b<0){
      cout<<yesno(false)<<endl;
      return 0;
    }
    if(x-b<0){
      cout<<yesno(false)<<endl;
      return 0;
    }
  }else{
    cout<<yesno(false)<<endl;
    return 0;
  }
  cout<<yesno(true)<<endl;
  return 0;
}
