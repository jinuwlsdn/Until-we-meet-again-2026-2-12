#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>




using namespace std;

const int MAX = 50;
int w,h;
int land[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int y, int x){

  
  for(int i = 0 ; i < 8; ++i ){
    int ny = y+dy[i];
    int nx = x+dx[i];

    //섬이고 방문 X

    

    if(0<= ny && ny < h && 0<=nx && nx<w ){
      //범위 안에 있으면
      if(land[ny][nx] && !visited[ny][nx]){
        visited[ny][nx] = true;
        dfs(ny,nx);
      }
    }
  }
}


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 2667번 문제랑 비슷한데 대각선까지도 섬으로 연결하는 부분이 추가됐네 그러면 이동할 수 있는 가짓수가 8


  //2. 시간복잡도 똑같이 O(V+E) = v에다가 이동할수있는 간선이 8개니까 9v  v는 n^2 2500은 1억보다 작다.

  //3. 이차원배열 및 bool visited 2차원배열에서 탐색이니까 4가지 방향 생성해야한다.
  

  //4 이차원배열의 값은 들어올때마다 초기화를 해줬는데 visited의 값은 초기화를 해주지 않았다.
  //memset 사용


  //4963

  
  

  //너비가 w 높이가 h
  while(1){


    memset(visited, false, sizeof(visited));
    memset(land , 0 , sizeof(land));

    

    int count = 0;
    cin >> w >> h;
    if(w == 0 && h == 0){
      break;
    }

    for(int i = 0; i<h; ++i){
      for(int j = 0 ; j<w ;++j){
        
        cin >> land[i][j];
      }
    }

    
    for(int i = 0; i<h; ++i){
      for(int j = 0 ; j<w ;++j){
        if(land[i][j] && !visited[i][j]){
          //섬

          visited[i][j] = true;
          dfs(i,j);
          count++;

        }


      }

      
    }


    cout << count << '\n';
  }


  return 0;
}