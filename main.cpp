#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;



int n,m,r;
int result[100001];
vector<int> v[100001];
bool visited[100001];


void dfs(int depth, int curr){

  visited[curr] = true;
  result[curr] = depth;


  for(int next : v[curr]){
    if(!visited[next]){
      dfs(depth+1 , next);
    }
  }



}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //24481
  //24444

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 전역 변수로 몇번째 방문했는지 기록하는 것이 아닌 dfs의 매개변수로 depth값을 준다.
  // 만약 주어진 예제 입력 1에서 5와 1이 연결되어있었다면 5는 1로 출력이 될것이다.

  //2. 시간복잡도 O(V+E) : ?

  //3. vector , bool visited


  cin >> n >> m >> r;

  memset(result, -1, sizeof(result));

  //fill_n(result, 100001, -1);
  for(int i = 0; i < m ; ++i){
    int p,q;
    cin >> p >> q;

    v[p].push_back(q);
    v[q].push_back(p);
  }

  for(int i = 1 ; i <=n ;++i){
    sort(v[i].begin(), v[i].end());
  }

  dfs(0,r);

  for(int i = 1; i <=n ;++i){
    cout << result[i] << '\n';
  }

 
  return 0;
}