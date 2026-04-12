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

  

  
  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //2565

    //1 A전봇대 B전봇대를 구분해보자 A전봇대 요소를 i , j(i보다 큰 정수)
    //i>j는 무조건 보장된다. (전봇대에서 보았을 때) 
    //그렇다면 a전봇대와 연결되어있는 b전봇대 요소를 b[i]라고 했을 때
    //만약 b[i] > b[j]라면 이 전깃줄은 절대 만나지 않는다. (i,j) 
    //따라서 b에서 i>j가 보장되어 있으므로 가장 긴 증가하는 수열을 찾아서 풀어주면 된다. 

    //4 입력이 1,2,3,4 차례대로가 아니라 1,4,2,3 꼬아서 주어질 수 있다.
    

    int n;
    cin >> n;
    vector<pair<int,int>> wires(n);

    for(int i = 0 ; i<n; ++i){
      cin >> wires[i].first >> wires[i].second;
    }

    //sort는 기본적으로 오름차순
    sort(wires.begin(), wires.end());

    vector<int> dp(n,1);
    
    int max_value =0;
    for(int i = 0;  i<n; ++i){

      for(int j = 0 ; j<i ; ++j){
        if(wires[j].second < wires[i].second){
          dp[i] = max(dp[i], dp[j]+1);
        }
      }
      max_value = max(max_value, dp[i]);
    }


    //전체 전선의 개수에서 가장 많이 남긴 개수 빼준다
    //그렇게 되면 우리가 제거해야할 전선의 개수가 나온다. 
    cout << n-max_value << '\n';
    

    return 0;

  }




















  

  //The reason why I miss you lies in your smile