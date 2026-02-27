#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;



int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  //1806

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점



  //1. S 이상 되는 것 중 가장 짧은 것의 길이. 투포인터로 문제를
  // 풀되 index 값으로 접근 하면 될 것 같다


  //2 0.5초 5천만 N번만 탐색한다면 O(N) 이므로 1e5 가능.

  //3 vector 백만 바이트가 1mb 40만바이트는 0.4mb 

  //4 index값 조정 


  int n,s;

  cin >> n >> s;

  vector<int> v(n);

  for(int i = 0 ; i <n ; ++i){
    cin >> v[i];
  }
  // 부분합 중에 그 합이 S 이상이 되는 것 중,

  int start = 0;
  //int end = 0;
  int sum = 0;
  int min_len = 1e7;
  

  
  for(int end = 0 ; end < n ; ++end){

    sum += v[end];
    
    while(sum >= s){
      min_len = min(min_len, end-start+1);

      sum -= v[start++];
    }
    

  }

  
  if(min_len == 1e7) cout << 0 << '\n';
  else cout << min_len << '\n';
    
  
  
  

  

  
  return 0;
}