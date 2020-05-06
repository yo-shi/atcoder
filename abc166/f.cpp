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
  int n,a,b,c;cin>>n>>a>>b>>c;
  map<char,int> val;
  val['A']=a;
  val['B']=b;
  val['C']=c;
  vector<char> ans(n);
  bool res=true;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    int v=val['A']+val['B']+val['C'];
    if(v==0){
      res=false;
      break;
    }else if(v==1){
      if(val[s[0]]+val[s[1]]==0){
        res=false;
        break;
      }
      if(val[s[0]]==0){
        val[s[0]]++;
        val[s[1]]--;
        ans.push_back(s[0]);
      }else{
        val[s[0]]--;
        val[s[1]]++;
        ans.push_back(s[1]);
      }
    }else if(v>=2){
      if(val[s[0]]+val[s[1]]==0){
        res=false;
        break;
      }
      if(val[s[0]]+val[s[1]]==1){
        if(val[s[0]]==0){
          val[s[0]]++;
          val[s[1]]--;
          ans.push_back(s[0]);
        }else{
          val[s[0]]--;
          val[s[1]]++;
          ans.push_back(s[1]);
        }
      }
    }
    if(val[s[0]]+val[s[1]]==0){
      res=false;
      break;
    }
    if(val['A']<0||val['B']<0||val['C']<0){
      res=false;
      break;
    }
  }
  cout<<outputYesNo(res)<<endl;
  if(res){
    for(int i=0;i<n;i++){
      cout<<ans[i]<<endl;
    }
  }
  return 0;
}
