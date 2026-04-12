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
  #include <deque>


  using namespace std;

  typedef long long ll;

  typedef pair<int, int> pii;

  const int INF = 1e9;

  

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  
  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //16234

    //1. L명이상 R명이하 
    //O(V+E) 50*50 + 50*50*4 
    //인구이동 발생하는 일수가 2000번보다 작다.
    //5*50*50 12500 * 2000    25 000 000.

    int n,l,r;
    cin >> n >> l >> r;

    if(n==1){
      cout << 0 << '\n';
      return 0;
    }

    vector<vector<int>> country(n+1, vector<int>(n+1, 0));

    for(int i= 0; i  <n ; ++i){
      for(int j = 0 ; j<n; ++j){
         cin >> country[i][j];
      }
    }

    //사이클마다 bfs탐색을하고 만족하는 나라는 좌표값을 넣어둔다. 인구수도 sum += 해준다.
    //sum/count를 한 다음 나온 값을 만족하는 나라에 저장한다. 
    

    
    int day_count = 0;
    while(1){
      bool check = false;
      
      vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
      queue<pair<int , int>> q;

      


      
      //횟수는 2500보다 밑이다.
      for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
          if(!visited[i][j]){
            queue<pair<int,int>> q;
            vector<pair<int,int>> coord;

            q.push({i,j});
            visited[i][j] = true;
            coord.push_back({i,j});
            int sum = country[i][j];


            while(!q.empty()){
              int y = q.front().first;
              int x = q.front().second;

              q.pop();


              for(int d = 0 ; d < 4 ; ++d){
                int ny = y +dy[d];
                int nx = x +dx[d];

                if(0<=ny && ny < n && 0<=nx && nx < n){
                  int diff = abs(country[y][x] - country[ny][nx]);

                  if(l<=diff && diff <= r){
                    visited[ny][nx] = true;
                    q.push({ny,nx});
                    coord.push_back({ny,nx});
                    sum += country[ny][nx];
                  }
                }
              }
            }

            //2개이상 묶인 나라가 있다.
            if(coord.size() > 1){
              //인구이동을 하였다.
              check = true;
              int value = sum / coord.size();
              for(pair k : coord){
                country[k.first][k.second] = value;
              }
            }


          }
          
        }
      }

      //check가 false면 인구이동이 한번도 없었다는 뜻이므로 종료한다.
      //아니면 day_count++한다.
      if(!check) break; 

      day_count++;
      

      
      
    }
    

    cout << day_count << '\n';


    return 0;
  }









  

  //The reason why I miss you lies in your smile