#include <cstdlib>
#include <iostream>



using namespace std;


int s[501][501];
bool visited[501][501];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};



int main(){

  


  // 1.아이디어 2.시간복잡도 3. 자료구조

  //1. 1 그리고 방문을 하지 않은 vertex에 들어가서 간선을 다 재본후에 count , max_area 구한다
  //이때 중요한건 방문을 했으면 했다고 남겨줘야한다.


  //2. O(V+E) V는 500 * 500 이고 E는 최대 4V이므로 5V 값은 2억보다 작다. 시간초과 되지 않는다.

  //3. 0 1값을 저장할 2차원배열과 bool visited를 설정한다. bfs이므로 queue자료구조를 사용해서
  //들어간 순서대로 탐색하도록 한다.
  //그리고 상하좌우로 이동해야하므로 4개의 공간을 가진 배열을 생성한다.

  int n,m;

  cin >> n >> m;



  //값을 넣는다.
  for(int i = 1 ; i <= n ; ++i){
    for(int j =  1;  j<=m ; ++j){
      cin >> s[i][j];
    }
  }


  







  return 0;
}