#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

typedef long long ll;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //2473
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  int n;
  cin >> n;

  vector<ll> v(n);

  for(int i = 0 ; i<n; ++i){
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  ll min_diff = 3e10;
  vector<ll> ans(3);

  for(int i = 0 ; i < n ; ++i){
    //i로 돌아가면서 모든 상황에 대해서 계산

    int l = 0 , r = n-1;

    while(l<r){

      if(l==i){
        ++l;
        continue;
      }
      if(r==i){
        --r;
        continue;
      }

      ll sum = v[i] + v[l] + v[r];

      if(min_diff > abs(sum)){
        
        min_diff = abs(sum);
        ans[0] = v[i];
        ans[1] = v[l];
        ans[2] = v[r];

        if(sum == 0) break;
      }

      if(sum < 0){
        ++l;
      }
      else{
        --r;
      }
    }



  }



  sort(ans.begin(), ans.end());

  for(int k  : ans){
    cout << k << " ";
  }


  return 0;
}