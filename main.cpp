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


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //1912
  
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //1. 연속된 몇개의 수를 더하는데 음수가 나오면 무조건 값이 원래 더한것보다 작아진다.
  //전에 연속되는 수를 더하다가 특정한 조건(음수)이 나오면 다시 합을 만든다.

  //2. n은 십만이하 일일이 하나씩 더하면 시간초과 따라서 DP로 풀어야한다.

  //3. 주어지는 수가 -1000 ~ 1000 따라서 int , 배열로 받아야한다.


  int n;
  cin >> n;
  vector<int> seq(n);

  for(int i = 0 ; i < n ; ++i){
    cin >> seq[i];
  }


  int sum = seq[0]; 
  int max_value = seq[0];
  for(int i = 1 ; i < n ; ++i){
    sum = max(seq[i], seq[i] + sum);

    if(sum > max_value) max_value = sum;
  }

  
  cout << max_value << '\n';


  


  return 0;
}