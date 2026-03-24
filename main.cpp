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

  int maze[126][126];
  int dist[126][126];

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};


  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);


    
    //4485
    //9370
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


    //1 (0,0)에서 (n-1,n-1) 까지 이동한다.
    //잃는 금액을 최소로 한다는건 최단 경로를 의미한다.
    //데이크스트라 알고리즘을 사용하여 풀면 될것같다.

    //2. O(ElogV) (125*4) * log125 2^7 = 128 약 6.~~ 
    //한번 하는데 500 * 6.~~  약 3000

    int n;
    int count = 1;

    while(1){
      cin >> n;
      if(n == 0 ) break;

      //좌표 입력받고
      for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
          cin >> maze[i][j];
          dist[i][j] = INF;
        }
      }

      //{가중치 , {(x,y)}} 로 받아서 우선순위큐에 넘겨줘야한다.
      priority_queue<pair<int, pii>, vector<pair<int , pii>>, greater<pair<int,pii>>> pq;

      pq.push({maze[0][0], {0,0}});

      dist[0][0] = maze[0][0];

      while(!pq.empty()){
        int d = pq.top().first;

        int y = pq.top().second.first;
        int x = pq.top().second.second;

        pq.pop();

        
        if(y == n-1 && x == n-1) break;
        if(dist[y][x] < d) continue;

        for(int i = 0 ; i < 4 ; ++i){
          int ny = y + dy[i];
          int nx = x + dx[i];

          if(0<= ny && ny < n && 0<= nx && nx < n){
            //좌표 값은 맞다.

            if(dist[ny][nx] > d + maze[ny][nx]){
              //최단 경로인가?
              
              dist[ny][nx] = d + maze[ny][nx];
              pq.push({dist[ny][nx] , {ny,nx}});
            }
          }
        }


        

      }

      printf("Problem %d: %d\n",count,dist[n-1][n-1]);
      
      count++;
    }



    return 0;
  }