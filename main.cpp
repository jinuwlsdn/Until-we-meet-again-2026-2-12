#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>
#include <map>


using namespace std;

typedef long long ll;


int graph[1025][1025];
int dp[1025][1025];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //11660
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //표를 그려서 생각해보면 된다. 직사각형들의 합으로 dp를 구현해야한다.
  //출력을 할 때에도 직사각형들의 모음으로 합을 구해야한다.


  int n,m;

  cin >> n >> m;

  // for(int i= 1 ; i<= n ; ++i){
  //   for(int j = 1 ; j <= n ; ++j){
  //     cin >> graph[i][j];
  //   }
  // }

  int temp = 0;

  for(int i= 1 ; i<= n ; ++i){
    for(int j = 1 ; j <= n ; ++j){
      cin >> temp;
      dp[i][j] = dp[i-1][j] + dp[i][j-1] + temp - dp[i-1][j-1];
    }
  }


  // for(int i= 1 ; i<= n ; ++i){
  //   for(int j = 1 ; j <= n ; ++j){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << '\n';
  // }

  
  

  while(m--){
    int x1,y1,x2,y2;

    cin >> x1>>y1>>x2>>y2;

    

    int value = dp[x2][y2] - dp[x1-1][y2] -dp[x2][y1-1] + dp[x1-1][y1-1];

    cout << value << '\n';
  }


  return 0;
}