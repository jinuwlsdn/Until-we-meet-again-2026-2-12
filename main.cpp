#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>


using namespace std;

int s[501][501];
bool visited[501][501];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
//          좌 우 위 아래
int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  // 1.아이디어 2.시간복잡도 3. 자료구조

  //1926 

  //1. 그래프를 탐색하다가 아직 방문하지 않은 1이 나올경우 그 1로 들어가서 마지막 1
  //까지 흔적을 남기고 max_area 비교 그다음 그림 개수 ++ 
  
  //2. O(V+E)  : m*n + E(4*V) 그러면 5V  = 5*500*500      125 00 00 2초면 2억 가능

  //3. 2차원배열 , queue



  int n,m;
  cin >> n >> m;

  
  int count = 0 ;
  int max_area = 0;

  for(int i = 1 ; i <= n ; ++i){
    for(int j = 1 ;  j <= m  ; ++j){
      cin >> s[i][j];
    }
  }



  for(int i = 1 ; i <= n ; ++i){
    for(int j = 1 ;  j <= m  ; ++j){
      
      //n이 세로 m이 가로

      if(s[i][j] && visited[i][j] == false){
        queue<pair<int , int>> q;

        visited[i][j] = true;
        int k = 1;
        q.push({i,j});

        // 그 위치에서부터 탐색한다.

        while(!q.empty()){
          int y = q.front().first;
          int x = q.front().second;

          q.pop();
          

          for(int i = 0 ; i<4; ++i){
            int ny = y+ dy[i];
            int nx = x+ dx[i];

            if(1<=nx && nx <= m && 1<=ny && ny<=n){

              //좌표가 유효하다.
              
              if(s[ny][nx] && visited[ny][nx] == false){
                //값이 1 방문 X

                ++k;
                visited[ny][nx] = true;
                q.push({ny,nx});
              }

            }
          }

        }
        
        max_area =  max(max_area, k);
        count++;
      }
    }
  }



  cout << count << '\n' << max_area;
  




  return 0;
}