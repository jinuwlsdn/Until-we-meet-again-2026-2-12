#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100;

int paper[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n,k;


//m은 세로 n은 가로

int value = 0;
void dfs(int y, int x){

  visited[y][x] = true;
  value++;

  for(int i= 0 ; i < 4 ; ++i){
    int ny = y + dy[i];
    int nx = x + dx[i];


    if(0<= ny && ny < m && 0<= nx && nx < n){
      //좌표값이 알맞고

      if(!visited[ny][nx] && !paper[ny][nx]){

        dfs(ny,nx);
      }
    }
  }

}
int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //2583

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 좌표를 받은 후에 그 좌표 값을 통해서 paper에 해당구역을 1로 바꾸고
  //그 후에 dfs를 사용해서 넓이 값을 구하면 될 것 같다.

  //2. 시간복잡도 O(V+E) 2차원배열에서 MAX값이 100일때 100*100 시간제한 1초보다 작다.
  
  //3. 이차원배열 및 재귀함수 사용

  //4. 가로 세로 구별 잘하기. visited true 해주기


 
  cin >> m >> n >> k;

  //값을 저장할 저장공간 만들기

  vector<int> area;

  //세로가 m 가로가 n

  for(int i = 0 ; i < k ; ++i){
    int x1,x2,y1,y2;

    cin >> x1 >> y1 >> x2 >> y2;

    for(int y = y1; y < y2; ++y){
      for(int x = x1; x<x2 ; ++x){
        paper[y][x] = 1;
      }
    }

  }

  //탐색하면서 dfs


  
  for(int i = 0 ; i < m ; ++i){
    for(int j = 0 ; j < n ; ++j){
      
      if(!paper[i][j] && !visited[i][j]){
        //해당 구역이 0이고 방문 X

        value =0;
        dfs(i,j);
        area.push_back(value);
      }
    }
  }

  //둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

  sort(area.begin(), area.end());


  cout << area.size() << '\n';

  for(int item : area){
    cout << item << " ";
  }
  


  return 0;
}