#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

const int MAX = 4000000;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  //1644

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점



  //1 체를 써서 소수만 쓰고 그 다음에 연속된 소수의 합으로 나타내야하는데 어떻게 하면
  //연속되게 할 수 있을까..


  //2 O(N)만 돈다고 하면 4000000

  //3 백만 바이트가 1mb 16mb 

  //4 index값 조정 

  int n;

  cin >> n;

  vector<bool> isprime(MAX+1, true);
  vector<int> prime_num(283146+1);

  //0과 1은 소수가 아니다.
  isprime[0] = isprime[1] = false;

  int idx =0;

  for(int i = 2; i <= sqrt(MAX); ++i){
    if(isprime[i]){

      for(int j = i*i ; j <= MAX ; j+=i){
        isprime[j] = false;
      }
    }
  }

  for(int i = 2; i <= MAX ; ++i){
    if(isprime[i]) prime_num[idx++] = i;
  }

  
  int cnt = 0;

  int start =0;
  
  int sum = 0;
 
  int end = 0;

  int prime_count = idx;

  while(true){
    if(sum >= n){
      if(sum == n) cnt++;
      sum -= prime_num[start++];
    }
    else if(end == prime_count){
      break;
    }
    else{
      //합이 n보다 작다
      sum += prime_num[end++];
    }

  }


 

  cout << cnt << '\n';

  
  return 0;
}