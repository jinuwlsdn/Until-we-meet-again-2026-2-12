  #include <cstdlib>
  #include <queue>
  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <cstring>
  #include <set>
  #include <cmath>
  #include <map>
  #include <iomanip> 
  //The reason why I miss you lies in your smile





  using namespace std;

  typedef long long ll;

  typedef pair<int, int> pii;

  const int INF = 1e9;
  int n,m;
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  
  vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

  void recurse(vector<vector<int>> graph ,int x, int y,int count){

    if(count == 3) return;

    for(int i = 0 ; i<n; ++i){
      for(int j = 0 ; j<n; ++j){
        if(graph[i][j] == 0){
          //빈칸이다
          graph[i][j] = 1;
          recurse(graph, i,j, count+1);
          graph[i][j] = 0;
        }
      }
    }
  }
  
  

  

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);

     

    
    //14502

    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //벽 3개를 만들고 바이러스가 있다면 퍼지게 하면서 count++한다. bfs로 풀어보자.
    //min_count를 계산하여 출력하면 된다.

    //bfs O(V+E); V의 최댓값은 8*8 이고 간선의 최댓값은 8*8*4 벽 3개 둘 수 있는 경우의 수는
    //64C3 41664 * O(V+E) = 41664 * (64+64*4)  13,332,480
    //n은 세로 m은 가로

    //삼중for문? 재귀함수? 
    
    cin >> n >> m;

    

    int safe_zone =0;
    queue<pair<int, int>> new_q;
    for(int i = 0 ; i <n ; ++i){
      for(int j = 0 ; j < m ;++j){
        cin >> graph[i][j];
        if(graph[i][j] == 2){
          new_q.push({i,j});
        }
        if(graph[i][j] == 0) safe_zone++;
      }
    }

    int max_safezone =0;
    for(int i = 0 ; i <n ; ++i){
      for(int j = 0 ; j < m ;++j){
        
        vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));

        //recurse로 반환될 수 있는 경우의 수는 매우 많다.
        //한번만 되는 것이 아닌가?
        recurse(graph, i,j,0);
        queue<pair<int,int>> q = new_q;

        int count_virus = 0;
        while(!q.empty()){
          int y = q.front().first;
          int x = q.front().second;

          q.pop();

          visited[y][x] = true;

          for(int i = 0 ; i < 4 ; ++i){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(0<=nx && nx < m && 0<=ny && ny<n){
              if(!visited[ny][nx] && graph[ny][nx] == 0){
                visited[ny][nx] = true;
                graph[ny][nx] = 2;
                count_virus++;
                q.push({ny,nx});
              }
            }
          }

        }

        int total_safezone = safe_zone - count_virus;
        max_safezone = max(max_safezone, total_safezone);

        


      }
    }


    
    return 0;
  }