#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

vector<int> min_city;
vector<int> cities[300001];
bool visited[300001];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //18352
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. dfs를 썼을땐 한번에 하나만 검사하니까 얘가 최단거리인지 아니면 구불구불하게 왔는지 모르는데
  //bfs를 쓰면 구불구불하게 오지 않고 바로 최단거리로 오기때문에 

  //2. 이런 경우에는 시간복잡도를 어떻게 구하는거


  int n,m,k,x;

  cin >> n >> m >> k >> x;

  //거리가 K 출발 도시 번호가 X

  for(int i =0 ; i < m ; ++i){
    int p,q;
    cin >> p >> q;

    cities[p].push_back(q);
    cities[q].push_back(p);
  }

  queue<pair<int,int>> q;

  q.push({x,0});
  visited[x] = true;

  while(!q.empty()){

    int curr = q.front().first;
    int len = q.front().second;

    q.pop();

    if(len == k){
      min_city.push_back(curr);
      continue;
      //값을 넣고 k를 넘어가면 어떤 도시도 답이 될 수 없다.
    } 
    for(int next : cities[curr]){
      if(!visited[next]){
        //next가 되는 값이 방문 X 
        //다른 도시에서 넣어도 최단거리는 아닌데 중복해서 넣으면 안되기 때문에

        visited[next] = true;
        q.push({next, len+1});
      }
    }


  }





  sort(min_city.begin(), min_city.end());

  if(min_city.size() == 0) cout << -1 << '\n';
  else{
    for(int it : min_city){
      cout << it << '\n';
    }
  }

  return 0;
}