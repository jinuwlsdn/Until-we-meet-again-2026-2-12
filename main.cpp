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

  int graph[101][101];

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);


    
    //11404
    
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


    int n,m;
    cin >> n >> m;

    //n+1개 줄에 n+1개의 칸을 만드는데 그 칸을 INF로 초기화
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    
    for(int i = 1 ; i <= n; ++i){
      graph[i][i] = 0;
    }

    for(int i = 0 ; i < m ; ++i){
      int a,b,c;

      cin >> a >> b >> c;
      graph[a][b] = min(graph[a][b], c);
    }

    for(int k = 1 ; k <= n ; ++k){
      for(int i = 1;  i<=n ; ++i){
        for(int j = 1 ; j<=n ; ++j){
          if(graph[i][k] != INF && graph[k][j] != INF){
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
          }
        }
      }
    }

    for(int i = 1; i <=n ; ++i){
      for(int j = 1 ; j <=n ; ++j){
        if(i == j && graph[i][j] >= INF){
          cout << 0 << " ";
        }
        else{
          cout << graph[i][j] << " ";
        }

      }
      cout << '\n';
    }
    
    return 0;
  }