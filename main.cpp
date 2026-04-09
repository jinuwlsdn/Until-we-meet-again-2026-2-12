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

    ios::sync_with_stdio(false);
    cin.tie(0);


    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //1002

    //1. 좌표평면에서 그려보면서 파악하고있다

    int t;
    cin >> t;

    while(t--){
      int x1,y1,r1,x2,y2,r2;

      cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
      
      if(x1 == x2 && y1 == y2){
        if(r1==r2) cout << -1 << '\n';
        else cout << 0 << '\n';
        continue;
      }

      //계산

      //예제입력에서 경우의 수를 다 주었다.
      //두 원이 있다고 가정했을 때 
      //두 원의 중점 사이의 거리 d와 반지름 r1,r2를 비교하여 출력값을 조정하면 될 것 같다.

      double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2,2));

      if(dist > r1+r2 || dist+r1<r2 || dist+r2 < r1) cout << 0 << '\n';
      else if(dist == r1+r2 || r2 == dist + r1 || r1 == dist + r2) cout << 1 << '\n';
      else if(dist < r1+r2) cout << 2 << '\n';
      

      
      //거리가 반지름의 합보다 클 때 혹은 원 안에 원이 있다는 가정, 두 원의 중점 사이의 거리 d와
      //작은 원의 반지름을 더 한 것이 큰 원의 반지름보다 작으면 교점이 없다
      //거리와 반지름의 합이 같거나, 원 안에 원이 있고 d와 작은 원의 반지름의 합이 큰 원의 반지름과
      //같다면 교점이 1개이다 
      //두원의 반지름 합이 d보다 크다면 교점이 2개다 원 안에 원이 있을 때도 원 밖에 원이 있을 때도
    }

    

    

  }




















  

  //The reason why I miss you lies in your smile