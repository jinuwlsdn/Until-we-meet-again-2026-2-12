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

int dp[101];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //9461
  
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;


  int T;
  cin >> T;

  for(int i = 6; i<101; ++i){
    dp[i] = dp[i-5] + dp[i-1];
  }

  while(T--){
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  
  


  return 0;
}