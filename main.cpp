#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

//const int MAX = 100000;
vector<int> v[100001];
long long di[100001];
long long ti[100001];
bool visited[100001];
int n,m,r;
int orders = 1;

void dfs(int curr, int depth){

  ti[curr] = orders++;
  visited[curr] = true;
  di[curr] = depth;

  for(int next : v[curr]){
    if(!visited[next]){
      dfs(next, depth+1);
    }
  }


}


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //24483
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  
  memset(di, -1 , sizeof(di));
  memset(ti, 0 , sizeof(ti));
  
  cin >> n >> m >> r;

  

  for(int i = 0 ; i < m ;  ++i){
    int p,q;

    cin >> p >> q;

    v[p].push_back(q);
    v[q].push_back(p);
  }

  //오름차순방문
  for(int i = 1 ; i<=n ; ++i){
    sort(v[i].begin(), v[i].end());
  }

  dfs(r,0);


  long long sum = 0;
  for(int i = 1 ; i <= n; ++i){
    sum += di[i] * ti[i];
  }
  cout << sum << '\n';

  return 0;
}