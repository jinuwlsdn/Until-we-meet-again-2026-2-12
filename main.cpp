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

vector<pii> adj[1001];
int dist[1001];
bool visited[1001];

const int INF = 1e9;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //1916
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  

  //O(ElogV) E는 100000이고 V는 1000 log1024 = x 2^x = 1024 x는 10
  //O(ElogV) 는 100000 * 10  백만

  int n,m;
  cin >> n >> m;

  for(int i = 0 ; i < m ; ++i){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    
  }

  int start,end;
  cin >> start >> end;

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  fill(dist, dist+n+1, INF);

  pq.push({0,start});
  dist[start] =0;

  //간선의 개수 N-1 * 비용  = 최댓값 99,900,000

  while(!pq.empty()){
    int d= pq.top().first;
    int curr = pq.top().second;

    pq.pop();

    if(dist[curr] < d) continue;

    if(curr == end) break;

    for(auto& edge : adj[curr]){
      int next_w = edge.first;
      int next_node = edge.second;

      if(dist[next_node] > d + next_w){
        dist[next_node] = d + next_w;
        pq.push({dist[next_node], next_node});
      }
    }
  }


  cout << dist[end] << '\n';

  return 0;
}