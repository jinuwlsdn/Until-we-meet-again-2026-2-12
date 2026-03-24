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

  int maze[101][101];
  int dist[101][101];

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};


  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    
    //1261
    //9370
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //1. 방을 이차원배열을 설정하고 각 배열마다 상하좌우로 adj에 넣는다
    // 상하좌우로 값을 넣으면서 방이면 가중치가 0 벽이면 1로 넣는다
    //만약 x,y지점까지 도달할 때 얼마나 많은 벽이 깨졌는지로 
    //최단경로를 설정한다. 1,1에서 n,m이니까 
    //마지막에 출력할때는 dist[n][m]출력하면된다 
    

    int m,n;

    cin >> m >> n;


    //세로는 n 가로는 m
    for(int i = 1 ; i<=n ; ++i){
      string line;
      cin >> line;

      for(int j = 1 ; j<=m; ++j){
        maze[i][j] = line[j-1] - '0';
        dist[i][j] = INF;
      }
    }

    
  
    priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int, pii>>> pq;


    dist[1][1] =0;
    pq.push({0,{1,1}});

    //fill(dist[0][0], dist[100][101], INF);

    while(!pq.empty()){

      
      int d = pq.top().first;

      int y = pq.top().second.first;
      int x = pq.top().second.second;

      pq.pop();

      if(dist[y][x] < d) continue;


    

      for(int k = 0 ; k<4; ++k){

        int ny = y+dy[k];
        int nx = x+dx[k];

        if(1<=ny && ny <= n && 1<=nx && nx <= m ){
          
          int weight = maze[ny][nx];
          if(weight + d < dist[ny][nx]){
            pq.push({weight+d,{ny,nx}});
            dist[ny][nx] = weight + d;
          }
          
        }
        
      }


    }

    cout << dist[n][m] << '\n';

    return 0;
  }