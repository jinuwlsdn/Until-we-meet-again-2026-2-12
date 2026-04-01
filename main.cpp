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


    
    //11403
    
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //플로이드 알고리즘을 사용하는데 k를 거쳐간다고 했을때
    //g[i][k] 가 1이고 g[k][j]가 1이면 i->j로 가는 길이 있으니까 g[i][j]을 1로 바꾼다
    //이렇게 1로 바꾸면 길이 계속 생기니까 나중에 길을 완성할 때도 도움이 된다.

    int n;
    cin >> n;

    vector<vector<int>> v(n+1, vector<int>(n+1, 0));

    //정수 값으로 줬다.
    for(int i = 1; i<=n ;++i){
      for(int j = 1;  j<=n ;++j){
        cin >> v[i][j];
      }
    }

    for(int k =1 ; k <=n ;++k){
      for(int i = 1;  i<=n ;++i){
        for(int j = 1; j <=n ; ++j){
          if(v[i][j]) continue;
          if(v[i][k] == 1 && v[k][j] == 1){
            v[i][j] = 1;
          }
        }
      }

      cout << k << "단계"  << '\n';
      for(int i = 1 ; i <= n ;++i){
        for(int j =1 ; j <=n ;++j){
          cout << v[i][j] << " ";
        }
      cout << '\n';
      }
    }
    // for(int k =1 ; k <=n ;++k){
    //   for(int i = 1; i <=n ; ++i){
    //     if(v[i][k] == 1 && v[k][i] == 1){
    //       v[i][i] = 1;
    //     }
    //   }    
    // }
      
    


  

    return 0;
  }