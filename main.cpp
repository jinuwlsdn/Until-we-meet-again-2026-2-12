#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>




using namespace std;

const int MAX = 100;

int n;
char painting[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];

int result[2];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void dfs1(int y, int x, char color){

  visited[y][x] = true;

  //적록색약이 아닌 경우 

  for(int i = 0 ;  i<4 ; ++i){

    int ny = y + dy[i];
    int nx = x + dx[i];

    if(0<= ny  && ny < n && 0 <= nx && nx < n){
      //범위 안에 들어가고 

      if(painting[ny][nx] == color && !visited[ny][nx]){
        //색깔이 같고 방문하지않았으면 

        
        dfs1(ny,nx,color);
      }
    }

  }

}










int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //10026

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1 RGB로 입력을 받으면 적록색약인 사람이 봤을때, 아닌 사람이 봤을때 차이만 구별해서
  //코드를 완성하면 될 것 같다. 그러면 dfs함수를 2개를 작성해서 만들고 각각 값을 result[0]
  //result[1]에 저장해서 출력하면 된다

  //2. 시간복잡도 O(V+E) n이 100이므로 n^2의 값이 1초보다 작다.

  //3. 재귀함수와 n이 100이므로 이차원배열을 사용해도 될 것 같다. 

  //4. visited체크 


  
  cin >> n;


  for(int i = 0 ; i < n ; ++i){
    string line;
    cin >> line;

    for(int j = 0 ; j<line.length(); ++j){
      painting[i][j] = line[j];
    }
  }



  //첫번째
  

  for(int i = 0 ; i < n ;++i){
    for(int j = 0 ; j<n; ++j){

      if(!visited[i][j]){
        result[0]++;

        //방문하지않았으면 
        dfs1(i,j,painting[i][j]);
      }


    }
  }


  //조건에 "색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다" 
  //라는 말이 있으니까 G를 R로 바꾸고 dfs1을 쓰면 될 것 같다.

  for(int i = 0 ; i < n ;++i){
    for(int j = 0 ; j<n; ++j){

      if(painting[i][j] == 'G'){
        painting[i][j] = 'R';
      }

    }
  }

  


  

  memset(visited, false, sizeof(visited));
  //두번째

   for(int i = 0 ; i < n ;++i){
    for(int j = 0 ; j<n; ++j){

      if(!visited[i][j]){
        result[1]++;

        //방문하지않았으면 
        dfs1(i,j,painting[i][j]);
      }


    }
  }
  
  


  cout << result[0] << " " << result[1] << '\n';


  return 0;
}