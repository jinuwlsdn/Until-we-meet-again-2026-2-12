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

  int dp[1001];


  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);


    
    //1965
    //9370
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0 ; i < n ; ++i){
      cin >> v[i];
      dp[i] = 1;
    }

    //dp[n]에 들어갈 수 있는건
    //n보다 작은 수 i
    //dp[i]들을 보면서 가장 큰 놈에다가 + 1 한 값을
    //dp[n]에 넣는다.

    //1000 * 1000 해도 시간 제한을 넘지 않는다.
    //상자의 크기는 1,000을 넘지 않는 자연수이다.
    //-> 최댓값이 int의 범위를 넘지않는다.

    int max_value = 1;
    
    for(int i = 0 ; i<n; ++i){
      dp[i] = 1;
      for(int j = 0 ; j<i; ++j){
        if(v[j] < v[i]){
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_value = max(max_value, dp[i]);
    }


    cout << max_value << '\n';

    
    
    return 0;
  }