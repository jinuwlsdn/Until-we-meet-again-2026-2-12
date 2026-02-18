#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>




using namespace std;

const int MAX = 25;

int graph[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int each = 0 ;

void dfs(int y, int x){

  //bfs랑 다르게 한곳만 파니까 처음부터 true로 적어도 된다.
  visited[y][x] = true;
  each++;

  for(int i = 0 ; i < 4 ; ++i){
    int ny = y + dy[i];
    int nx = x + dx[i];

    //좌표만들고 

    if( 0 <= ny && ny<n && 0<= nx && nx < n && !visited[ny][nx]){
      //방문을 안했음
      if(graph[ny][nx] == 1 && !visited[ny][nx]){
        dfs(ny,nx);
      }

    }
    
    
  }
}



int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //2667

  //1. DFS를 사용하여 푸는데 이때 사용하는건 재귀함수이다. 이차원배열을 탐색하다가
  //1의 값이 나오면 그 지점부터 DFS탐색을 실시한다. 

  //2. O(V+E) 이다 V는 n^2 e를 계산할 때에 정점에서 뻗어나갈 수 있는 e가 최대 4 이므로 4v
  //총 5v 5 * n^2 n의 최댓값은 25 625는 2억보다 작다. 가능
  
  //3. 자료구조 이차원배열 visited 

  //4. dfs 호출 까먹지말고 visited true  01001010 이렇게 주어지면 string으로 받아야된다.
  //그래프로 탐색해야하니까 dx dy를 만들어준다.


  

  cin >> n;

  string line;


  vector<int> v;


  

  for(int i = 0 ; i < n ; ++i){
    cin >> line;

    for(int j = 0 ; j < line.length(); ++j){
      graph[i][j] = line[j] - '0';
    }
  }

  for(int i = 0 ; i< n ; ++i){
    for(int j = 0 ; j<n;  ++j){
      if(graph[i][j] && !visited[i][j]){
        //1이고 방문하지않음 

        // i 는 y  j는 x

        each = 0;
        dfs(i,j);

        v.push_back(each);
        



      }
    }
  }


  sort(v.begin(), v.end());

  cout << v.size() << '\n';

  for(int item : v){
    cout << item << '\n';
  }
  

  return 0;
}