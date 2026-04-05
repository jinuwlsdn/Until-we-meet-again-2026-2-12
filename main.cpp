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



  using namespace std;

  typedef long long ll;

  typedef pair<int, int> pii;

  const int INF = 1e9;
  
  int graph[51][51];
  int dist[51][51];
  int n,m;
  vector<pair<int,int>> virus,selected;
  
 
  
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};

  
  int min_sec = INF;
  void bfs(){
   
    //-1 방문 X
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;

    for(auto& p : selected){
      q.push(p);
      dist[p.first][p.second] = 0;
      //0은 방문했다.
    }

    int max_time =0;

    while(!q.empty()){
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      for(int i = 0 ; i < 4 ; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(0<=ny && ny < n && 0<=nx && nx < n){
          if(graph[ny][nx] != 1 && dist[ny][nx] == -1){
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny,nx});
          }
        }
      }
    }
    bool judge = true;
    for(int i = 0 ; i<n; ++i){
      for(int j = 0 ; j<n; ++j){
        max_time = max(max_time, dist[i][j]);
        //방문할 수 있는 공간인데 방문을 하지 않았으면
        if(graph[i][j] == 0 && dist[i][j] == -1) judge =false;
      }
    }
    
    if(!judge) return;
    else{
      min_sec = min(min_sec, max_time);
      return;
    }

    

  }
  void recurse(int start_idx, int count){


    if(count == m){
      bfs();
      return;
    }

    //바이러스를 조합공식을 사용해서 넣는다.
    //큐를 만들어서 m개의 좌표를 넣는다.
    for(int i = start_idx; i<virus.size(); ++i){
      selected.push_back(virus[i]);
      recurse(i+1, count+1);
      selected.pop_back();
    }
    
  }


  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //17141
  
    //1. graph를 입력받고 백트래킹을 통해서 바이러스를 배치한다.
    //그 다음 bfs를 통해서 바이러스를 퍼뜨리고 최소시간을 구하면 된다.

   
    cin >> n >> m;

    for(int i = 0 ; i < n ; ++i){
      for(int j = 0 ;  j < n; ++j){
        cin >> graph[i][j];
        if(graph[i][j] == 2){
           virus.push_back({i,j});
           graph[i][j] = 0;
        }
      }
    }


    recurse(0,0);

    if(min_sec == INF) cout << -1 << '\n';
    else cout << min_sec << '\n';





  }




  //The reason why I miss you lies in your smile