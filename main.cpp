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

vector<pii> adj[100001];
bool visited[100001];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //1647
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  
  int n, m;

  cin >> n >> m;
  
  int a,b,c;

  for(int i = 0 ; i < m; ++i){
    cin >> a >> b >> c;

    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }


  priority_queue<pii, vector<pii>, greater<pii>> pq;

  

  //1억 이하
  int sum =0;
  int max_value =0;

  //마을을 분리하고 각각 분리된 마을에서도 경로가 항상 존재하게 하도록 하면서
  //나머지 길의 유지비의 합을 최소로 하고 싶다.
  //mst를 만들고 거기서 가장 유지비가 높은 간선 하나를 제거하면 된다.
  //

  pq.push({0,1});
  int count =0;
  while(!pq.empty()){
    int w  = pq.top().first;
    int curr = pq.top().second;

    pq.pop();

    if(visited[curr]) continue;

    //처음 방문했으면
    visited[curr] = true;
    sum += w;
    max_value = max(max_value, w);
    count++;

    for(auto& edge : adj[curr]){
      int nextweight = edge.first;
      int nextnode = edge.second;

      if(!visited[nextnode]){
        pq.push({nextweight, nextnode});
      }

    }

    //방문한 정점이 n개면 굳이 더 갈 필요가 없다 이미 mst를 만들어서
    if(count == n) break;

  }

  
  
  cout << sum - max_value << '\n';
  
  
  return 0;
}