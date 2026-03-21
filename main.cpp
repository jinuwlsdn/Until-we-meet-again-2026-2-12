#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>
#include <map>


using namespace std;

typedef long long ll;

typedef pair<int , int> pii;

vector<pii> adj[1001];
bool visited[1001];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //1197
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  
  int v,e;

  cin >> v >> e;
  for(int i=0 ; i <e; ++i){
    int u,v,w;
    cin >> u >> v >>w;

    adj[u].push_back({w,v});
    adj[v].push_back({w,u});
  }

  ll totalweight = 0;
  //가중치가 int범위를 넘을 수 있다.

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  pq.push({0,1});

  while(!pq.empty()){
    int w = pq.top().first;
    int curr = pq.top().second;

    pq.pop();

    if(visited[curr]) continue;

    visited[curr] = true;
    totalweight += w;

    for(auto& edge : adj[curr]){
      int nextweight = edge.first;
      int nextnode = edge.second;

      if(!visited[nextnode]){
        pq.push({nextweight, nextnode});
      }

    }

    
  }



  cout << totalweight << '\n';


  return 0;
}