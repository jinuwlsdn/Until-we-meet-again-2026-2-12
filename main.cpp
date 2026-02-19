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
queue<pair<int ,int>> q;
int m,n,k;

//m은 세로 n은 가로


int bfs(int y, int x){

  int value =0;
  
  q.push({y,x});
  visited[y][x] = true;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    

    value++;
    q.pop();

    for(int i = 0 ; i < 4 ; ++i){
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(0<= ny && ny < m && 0 <= nx && nx < n){
        //좌표값 부합하고

        if(!visited[ny][nx] && !paper[ny][nx]){

          q.push({ny,nx});
          visited[ny][nx] = true;
          
        }
      }
    }

  }


  return value;
}



int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //2583

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //BFS로 풀이

  

 
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

  //탐색하면서 bfs


  for(int i = 0 ; i < m ; ++i){
    for(int j = 0 ; j < n ; ++j){

      if(!visited[i][j] && !paper[i][j]){

        int area_value = bfs(i,j);

        area.push_back(area_value);
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