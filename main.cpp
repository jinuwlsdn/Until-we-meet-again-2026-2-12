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

typedef pair<double , double> pdd;
typedef pair<double, int> pdi;

vector<pdi> adj[101];
bool visited[101];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //4386
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //1.한 좌표에 대해서 모든 좌표를 돌리면서 가중치값과 
  //간선들을 서로서로 연결한다.

  //2. O(V + V^2 + ElogV) 간선이 100 * 100 임의의 간선을 만드니까 그리고 log V는 V가 100
  //V^2 가장 크다  100 * 100
  int n;

  cin >> n;

  vector<pdd> v(n);

  for(int i =0 ; i < n ; ++i){
    cin >> v[i].first >> v[i].second;
  }

  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < n ; ++j){
      if(i==j) continue;
      double length = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
      
      adj[i].push_back({length,j});

    }
  }

  priority_queue<pdi, vector<pdi>, greater<pdi>> pq;

  pq.push({0, 0});


  double totalweight = 0;
  int count = 0;
  while(!pq.empty()){
    double w = pq.top().first;
    int curr = pq.top().second;

    pq.pop();


    if(visited[curr]) continue;

    count++;
    visited[curr] = true;
    totalweight += w;

    for(auto& edge : adj[curr]){
      double next_w = edge.first;
      int next_node = edge.second;

      if(!visited[next_node]){
        pq.push({next_w, next_node});
      }

    }

    if(count == n) break;
  }


  cout << fixed << setprecision(2) << totalweight << '\n';

  return 0;
}