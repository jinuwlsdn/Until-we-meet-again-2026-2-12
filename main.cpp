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

    //1 플로이드 알고리즘을 쓰는데 이 때 본인을 0이 아닌 INF로 설정해서 graph i i 값도
    //만들어야한다. graph[i][i]가 0이면 어떤값을 넣어도 갱신이 될 수 없다.
    //자기 자신으로 돌아와야 사이클을 만들 수 있고 최솟값 갱신이 되어야 답을 구할 수 있다.

    //플로이드 알고리즘을 사용할 경우 시간 복잡도는 O(N^3) 400의 3제곱
    // 64 000 000

    //3 2차원배열의 vector를 사용, 출력값의 최댓값 400 * 10000 ?

    int v,e;
    cin >> v >> e;

    vector<vector<int>> graph(v+1, vector<int>(v+1,INF));

    for(int i = 0 ;  i < e ; ++i){
      int a,b,c;
      cin >> a >> b >> c;

      //a->b
      graph[a][b] = c;
    }

    int min_cycle =INF;
    for(int k =1 ; k <=v ;++k){
      for(int i =1 ; i<=v; ++i){
        for(int j = 1; j <=v ; ++j){
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
        
      }
    }

    for(int i = 1; i<=v ; ++i){
      min_cycle = min(min_cycle, graph[i][i]);
    }

    if(min_cycle == INF) cout << -1 << '\n';
    else cout << min_cycle << '\n';


    return 0;
  }