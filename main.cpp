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

  

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);

     

    
    //2458

    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점
    
    //1.본인한테 간선이 들어오거나 간선이 다른 정점을 향해 뻗어야 하는데 그 간선들의 수를 세보았을 때
    // n-1값이면 정확하게 본인의 위치를 알 수 있다.

    //이 문제가 왜 플로이드 알고리즘 -> m의 값이 n(n-1)/2로 주어진다는건 단방향 그래프라는 것이고
    //그래프를 통해서 각각의 정점들이 문제의 조건에 해당하는 정점인지 확인해야한다.
    //도달 가능 여부를 체크하기 위해


    //The reason why I miss you lies in your smile

    int n,m;
    cin >> n >> m;

    vector<vector<int>> students(n+1, vector<int>(n+1,INF));

    for(int i = 1; i <= n ; ++i){
      students[i][i] = 0;
    }

    for(int i = 0 ; i < m ; ++i){
      int a,b;
      cin >> a >> b;
      
      students[a][b] = 1;

    }


    //플로이드 알고리즘
    for(int k = 1; k <= n ; ++k){
      for(int i = 1 ; i<=n ; ++i){
        for(int j=1 ; j<=n; ++j){
          students[i][j] = min(students[i][j], students[i][k] + students[k][j]);
        }
      }
    }
    

    int total = 0;
    for(int i = 1; i <=n ; ++i){
      int count  =0;

      for(int j =1 ; j <=n ; ++j){
        if(i == j ) continue;
        if(students[i][j] < INF || students[j][i] < INF){
          // i->j 갈 수 있거나 j->i 쪽으로 들어 오거나
          //존재한다면
          count++;
        }
      }

      if(count == n-1) total++;
    }


    cout << total << '\n';
    
   
    return 0;
  }