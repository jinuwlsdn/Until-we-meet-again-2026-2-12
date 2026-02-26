#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;


int result[100001];
vector<int> v[100001];
bool visited[100001];
int cnt =0;
int n,m,r;

void dfs(int curr){
 
  visited[curr] = true;
  result[curr] = ++cnt;

  for(int next : v[curr]){
    if(!visited[next]){
      dfs(next);
    }
  }
  
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //24479

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 주어진 방문 순서 데이터 및 함수 구조로 dfs를 사용해 풀면 된다. 
  //이때 중요한건 오름차순

  //2. 시간복잡도 O(V+E) V는 100000 간선의수는 200 000 하지만
  //이때 Vector로 접근해야한다.

  //3 vector , bool visited
  
  //4. visited 수행 잘 하기. 시작 정점에서 방문할 수 없는 경우는 0을 출력 
  //숫자에 순서를 기입하기. 시작 정점의 방문순서는 1.


  

  cin >> n >> m >> r;

  for(int i = 0 ; i < m; ++i){
    int p , q;
    cin >> p >> q;

    v[p].push_back(q);
    v[q].push_back(p);

  }

  for(int i =1 ; i<=n ; ++i){
    sort(v[i].begin(), v[i].end());
  }
  

  dfs(r);

  for(int i = 1; i<=n ;++i){
    cout << result[i] <<'\n';
  }
  
  return 0;
}