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

vector<pii> adj[20001];
int dist[20001];

const int INF = 1e9;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //1753
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 데이크스트라 알고리즘을 사용하여 문제를 풀면될것같다.
  //이 때 u - > v 양방향이 아니다.
  //최단 경로의 경로값

  //O(ElogV) 300000 * log 20000 / 2^x = 20000 14.~~ / 14*300000 1억보다 작다.

  int v,e;

  cin >> v >> e;

  int k;
  cin>>k;

  for(int i = 0; i<e ; ++i){
    int u,v,w;
    cin >> u >> v >> w;

    adj[u].push_back({w,v});
  }

  dist[k] = 0;

  fill(dist , dist+v+1, INF);

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  pq.push({0,k});

  while(!pq.empty()){
    int d = pq.top().first;
    int curr = pq.top().second;

    pq.pop();

    if(dist[curr] < d) continue;

    dist[curr] = d;

    for(auto& edge : adj[curr]){
      int next_w = edge.first;
      int next_node = edge.second;

      if(dist[next_node] > d+next_w){
        dist[next_node] = d+next_w;
        pq.push({dist[next_node], next_node});
      }
    }

  }

  for(int i = 1; i <= v ; ++i){
    if(dist[i] == INF){
      cout << "INF" << '\n';
    }
    else{
      cout << dist[i] << '\n';
    }
  }

  return 0;
}