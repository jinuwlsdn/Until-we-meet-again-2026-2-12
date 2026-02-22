#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


const int MAX = 50;
int map[MAX+1][MAX+1];

//북 동 남 서
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //14503

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 문제에서 요구하는 대로 구현하면 될 것 같다

  //2. 시간복잡도 로봇청소기가 다 돌아다니는 경우는 N*M이고 2차원배열에서 로봇이 다닐 수 있는 가짓수는
  //4가지이므로 4*N*M인데 N,M의 최댓값이 50 2500 * 4는 10000이니까 충분하다.

  //3. 지도 데이터를 입력받을 이차원 배열 int d, int x, int y

  //4. 


  int n,m;

  cin >> n >> m;

  int y,x,d;

  cin >> y >> x >> d;

  //n이 세로 m이 가로

  for(int i =0 ; i <n ; ++i){
    for(int j = 0 ; j < m ; ++j){
      cin >> map[i][j];
    }
  }

  int cnt =0;

  // 0 북 1 동 2 남 3 서
  while(1){

    //judge가 0이면 청소할 칸을 찾은 것이고 1이면 못찾은것
    int judge = 1;

    //1
    if(!map[y][x]){
      map[y][x] = 2;
      cnt++;
    }
    //3
    //청소 X 찾아야된다.
    for(int i = 0 ; i<4; ++i){
      
      //청소를 하면서 빈칸이 있는지 확인해야한다.
      
      //반시계방향으로 90도 회전 
      d = (d+3) % 4;
      //반시계면  0 3 2 1
      //
      int ny = y+ dy[d];
      int nx = x+ dx[d];

      if(0<=ny && ny < n && 0<=nx && nx<m && !map[ny][nx]){
        y = ny;
        x = nx;
        judge =0;
        break;
      }
    }

    if(judge == 0) continue;

    //judge가 0이면 청소할 칸을 찾거나, 후진이 가능한 경우 1이면 못찾은것
    //청소를 한 칸은 2로 바꾸자


    //2
    if(judge){
      
      //d가 0이면 2 1이면 3 3이면 1 2면 0

     int back_d = (d+2) % 4;
     int by = y + dy[back_d];
     int bx = x + dx[back_d];

     if(0<= by && by < n && 0<= bx && bx < m && map[by][bx] != 1){
      //청소를 한 구역

      //0이거나 2면 청소를 안했거나 했다
      y = by;
      x = bx;
     }
     else break;
    }
   


  }

  cout<< cnt << '\n';
  
  return 0;
}