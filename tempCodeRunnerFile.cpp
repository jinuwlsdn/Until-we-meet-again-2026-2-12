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

  int item[101];
  int graph[101][101];
  bool visited[101];

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);


    
    //14938
    
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


    int n,m,r;


    for(int i = 1 ; i <=n ;++i){
      cin >> item[i]; 
    }

    for(int i = 0; i < r ; ++i){
      int a,b,l;
      cin >> a >> b >> l;

      graph[a][b] =l;
      graph[b][a] =l;
      
    }

    //처음 스타트 어디?

    for(int k =1 ; k<=n ;++k){
      for(int i =1 ; i<=n ;++i){
        for(int j =1 ; j<=n ;++j){
          if(graph[i][j] > graph[i][k] + graph[k][j]){
            graph[i][j] = graph[i][k] + graph[k][j];
          }
        }
      }
    }
    int max_sum =0;
    for(int i = 1; i <= n ;++i){
      int sum = 0;
      for(int j = 1;  j<=n ; ++j){
        if(graph[i][j] <= m){
          //수색 범위 안에있음
          sum += item[j];
        }
      }

      max_sum = max(max_sum , sum);
    }

    cout << max_sum << '\n';
    

  

    return 0;
  }