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


  
  
  //1446
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //지름길이 있는건 지름길을 사용하고 없으면 그냥가야한다.
  //만약에 0->30을 갔다고 하자 근데 29>100 직빵으로 가는 길이 있으면
  //지나칠수있다. dist++하면서 

  int n,d;

  cin >> n >> d;


  
  for(int i = 0 ; i<d ; ++i){
    adj[i].push_back({1,i+1});
  }

  for(int i = 0 ; i < n; ++i){
    int a,b,c;

    cin >> a >> b >> c;

    if(b>d) continue;

    adj[a].push_back({c,b});
  }

  dist[0] = 0;

  priority_queue<pii, vector<pii> , greater<pii>> pq;
  
  pq.push({0,0});

  fill(dist, dist+d+1, INF);

  while(!pq.empty()){
    int d = pq.top().first;
    int curr = pq.top().second;

    pq.pop();

    if(dist[curr] < d ) continue;

    dist[curr] = d;

    for(auto& edge : adj[curr]){
      int next_w = edge.first;
      int next_way = edge.second;

      if(dist[next_way] > next_w + d){
        dist[next_way] = next_w + d;
        pq.push({dist[next_way], next_way});
      }
    }


  }


  cout << dist[d] << '\n';
  

  return 0;
}