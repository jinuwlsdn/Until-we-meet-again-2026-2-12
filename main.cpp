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
  //The reason why I miss you lies in your smile





  using namespace std;

  typedef long long ll;

  typedef pair<int, int> pii;

  const int INF = 1e9;

  

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);

     

    
    //2660

    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //각 회원의 점수를 정할 때 주의할 점
    //어떤 두 회원이 친구사이이면서 동시에 친구의 친구사이이면, 이 두사람은 친구사이라고 본다.
    //-> 최단경로로 계산한다

    
    int n;
    cin >> n;

    vector<vector<int>> f(n+1, vector<int>(n+1, INF));

    for(int i = 1; i<=n; ++i){
      f[i][i] = 0;
    }

    while(1){
      int a,b;
      cin >> a >> b;
      if(a==-1 && b == -1) break;

      f[a][b] = 1;
      f[b][a] = 1;
    }

    for(int k =1 ;  k <=n ; ++k){
      for(int i =1 ; i<=n ;++i){
        for(int j =1 ; j <=n ; ++j){
          f[i][j] = min(f[i][j] , f[i][k]+ f[k][j]);
        }
      }
    }
    


    int min_score = INF;
    int person = 0;

    vector<int> values(n+1, 0);

    for(int i =1 ;  i <=n ; ++i){
      int score =0;
      for(int j =1 ;  j<=n ;++j){
        score = max(score, f[i][j]);
      }
      values[i] = score;
      min_score = min(min_score, values[i]);
    }

    vector<int> v;
    for(int i = 1; i <=n ; ++i){
      if(values[i] == min_score){
        v.push_back(i);
        person++;
      } 
    }

    cout << min_score << " " << person << '\n';
    for(int item : v){
      cout << item << " ";
    }
   
    
   
    return 0;
  }