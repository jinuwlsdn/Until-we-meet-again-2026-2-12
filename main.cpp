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

  int maze[1001][1001];
  int dp[1001][1001];

  int dx[3] = {-1,0,-1};
  int dy[3] = {0,-1,-1};
  

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);


    
    //11048
    //9370
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


    //1 dp로 최댓값을 각 배열마다 수정하면 된다.
    //(r,c) 에서 갈 수 있는건 r+1,c / r,c+1 / r+1, c+1
    //그러면 (x,y) 3가지의 경우를 조사해서 가장 최댓값을 찾으면 된다.
    //어차피 더해주는 maze[y][x]
    int n,m;

    cin >> n >> m;

    for(int i = 1 ; i <=n ; ++i){
      for(int j = 1 ; j<=m ; ++j){
        cin >> maze[i][j];
        dp[i][j] = maze[i][j];
      }
    }
    dp[1][1] = maze[1][1];


    for(int i = 1 ; i <=n ; ++i){
      for(int j = 1 ; j<=m ; ++j){
        
        for(int k = 0 ; k < 3 ; ++k){
          int nx = j + dx[k];
          int ny = i + dy[k];

          if(1<=ny && ny <= n && 1<=nx && nx <=m){
            dp[i][j] = max(dp[i][j], dp[ny][nx] + maze[i][j]);
          }
        }
      }
    }







    cout << dp[n][m] << '\n';
    
    
    return 0;
  }