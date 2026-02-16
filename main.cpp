#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>


using namespace std;

int com[101][101];
bool visited[101];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);



  //2606


  //1 아이디어 거쳐간 애들을 1 1 로 체크해서 for문돌려서 1인 애들만 count하려고 했으나 만약 순서가
  //원하는 대로 안나오면 값이 달라질 수 있음 연결되어있는 것을 나타내면 bfs로 충분히 탐색하면서
  //풀 수 있을 것 같은데. bfs dfs 둘다 가능하다

  //2 시간복잡도 O(V+E) V는 100 E는 99 199 근데 감염안된 컴퓨터도 체크해야하니까 100 * 100 해도 
  // 1억 안된다.

  //3 자료구조 서로 연결 되어 있음을 확인하는 2차원배열o  그다음에 방문했는지 안했는지 o.
  //queue자료구조


  int n,m;

  cin >> n >> m;

  for(int i = 0 ; i < m ; ++i){
    int one , two;

    cin >> one >> two;

    com[one][two] = 1; //연결되어있다
    com[two][one] = 1; 
  }

  queue<int> q;

  q.push(1);

  int count = 0 ;
  while(!q.empty()){
    int k = q.front();

    //처음에 1을 꺼냈고
    q.pop();
    visited[k] = true;

    for(int i = 1; i<=n ; ++i){
      if(com[k][i] && !visited[i]){
        count++;
        visited[i] = true;
        q.push(i);
        
      }
    }
  }


  cout << count << '\n';
  




  return 0;
}