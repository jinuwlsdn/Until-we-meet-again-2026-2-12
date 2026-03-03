#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int tomato[1001][1001];
//int result[1001][1001];
bool visited[1001][1001];


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //1 문제에서 시키는대로 구현만 하면 될 것 같다 근데 한 중심으로
  //퍼지는 부분이니까 bfs를 사용하면 될 것 같고 그래프에다가 값을 넣어서 !q.empty() 될때까지
  //작업을 시행한다 그리고 그래프에서 값을 탐색하면서 만약 0이 있다면 -1이고  모두 익어있으면
  //0을 출력하고 아니면 최소날짜기때문에 그래프중에서 가장 높은 값을 선택하면된다.
  //그래프 탐색하면서 값을 줄때 현재값 + 1을 주면 다음날로 저장이 된다.

  //2. O(V+E) 1000 * 1000 + 4 * 1000 * 1000 1억보다 작다.

  //3. 이차원배열 및 visited
  // 1000 * 1000 * 4 = 4000000 백만바이트 4mb 충분하다

  //visited 안하는거


  //1은 익은 토마토 0은 익지않은 토마토 -1은 들어있지 않은 칸

  int m,n; 
  //m은 가로 n은 세로

  cin >> m >> n;

   queue<pair<int,int>> q;

  for(int i = 0 ; i <n ; ++i){
    for(int j = 0 ; j < m ; ++j){
      cin >> tomato[i][j];
      if(tomato[i][j] == 1){
        visited[i][j]= true;
        q.push({i,j});
      }
    }
  }


  while(!q.empty()){

    int y = q.front().first;
    int x = q.front().second;

    q.pop();

    for(int i = 0 ; i<4 ; ++i){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx && nx < m && 0<=ny && ny < n){
        //범위안에 들어오고

        if(!visited[ny][nx] && tomato[ny][nx] != -1){
          visited[ny][nx] = true;
          tomato[ny][nx] = tomato[y][x] + 1;
          q.push({ny,nx});
        }
      }
    }
  }
  
  //값 확인
  //저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력 이 경우는 최댓값이 1

  // cout << '\n';

  // for(int i = 0 ; i < n ; ++i){
  //   for(int j = 0 ; j < m ; ++j){
  //     cout << tomato[i][j] << " ";
  //   }
  //   cout << '\n';
  // }

  int min_day = 0;
  bool check = false;

  for(int i= 0 ; i <n; ++i){
    if(check) break;
    for(int j=0 ; j<m ; ++j){
      //아무것도들어있지 않은거 패스
      if(tomato[i][j] == -1) continue;
      //익지않은거 한개라도 들어있으면
      if(tomato[i][j] == 0){
        min_day = 0;
        check = true;
        break;
      }
      min_day = max(min_day , tomato[i][j]);
    }
  }
  if(min_day == 1){
    cout << 0 << '\n';
  }
  else if(min_day == 0){
    cout << -1 << '\n';
  }
  else if(min_day > 1){
    cout << min_day-1 << '\n';
  }
 

  return 0;
}