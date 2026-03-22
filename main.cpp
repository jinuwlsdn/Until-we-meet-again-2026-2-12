#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <cmath>
#include <map>
#include <iomanip> 


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

vector<pii> adj[801];
int dist[801][801];

const int INF = 1e9;

void dijkstra(int start){

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  dist[start][start] = 0;

  pq.push({0,start});
  
  while(!pq.empty()){
    int d = pq.top().first;
    int curr = pq.top().second;

    pq.pop();

    if(dist[start][curr]  < d ) continue;

    dist[start][curr] = d;

    for(auto& edge : adj[curr]){
      int w = edge.first;
      int way = edge.second;

      if(dist[start][way] > d+w){
        dist[start][way] = d+w;
        pq.push({dist[start][way], way});
      }
    }

  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //1504
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1.

  int n,e;

  cin >> n >> e;
  
  for(int i = 0 ; i < e ; ++i){
    int a,b,c;

    cin >> a >> b >> c;

    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }


  fill(&dist[0][0], &dist[n][n+1], INF);

  int v1,v2;
  cin >> v1 >> v2;

  dijkstra(1);
  dijkstra(v1);
  dijkstra(v2);

  ll case1 = (ll)dist[1][v1] + dist[v1][v2] + dist[v2][n];
  ll case2 = (ll)dist[1][v2] + dist[v2][v1] + dist[v1][n];

  if(case1 >= INF && case2 >= INF){
    cout << -1 << '\n';
    return 0;
  }

  if(case1 > case2){
    cout << case2 << '\n';
  }
  else{
    cout << case1 << '\n';
  }



  return 0;
}