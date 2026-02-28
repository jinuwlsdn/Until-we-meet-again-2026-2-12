#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  //2230
  //2473
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. ?? ㅇㄴ 난감하네

  //2. ???

  int n,m;

  cin >> n >> m;

  //같은 수를 선택하라고 나올 수 있음 그땐 차이가 0일텐데 만약 m의 값이 0으로 주어졌다면
  //그땐 어떤 수열을 받아도 N이 1보다 크기 때문에 당연히 0이 가장 작은 갭이다.
  if(m == 0){
    cout << 0 << '\n';
    return 0;
  }

  vector<int> v(n);

  for(int i = 0;  i < n ; ++i){
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int start = 0;
  int end = 0;

  int gap = 0;
  int min_len = 2e9 + 1;

  while(end < n){

    
    gap = abs(v[start] - v[end]);

    if(gap >= m){
      if(gap == m){
        min_len = gap;
        break;
      }


      min_len = min(min_len, gap);
      start++;
    }
    else if(gap < m){
      end++;
    }
    



  }



  cout << min_len << '\n';
  



  return 0;
}