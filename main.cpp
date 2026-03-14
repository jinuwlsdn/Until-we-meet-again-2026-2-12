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


int yen[6] = {500,100,50,10,5,1};

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //1789
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  ll s;
  cin >> s;

  long long n =1;
  
  ll sum = 0;

  int count = 0;

  while(1){
    sum += n;
    if(sum > s) break;
    
    n++;
    count++;
  }

  //n의 최댓값은 63,245.55~
  //n을 최대로 돌린다고 해도 시간복잡도가 2억 밑이다.

  cout << count << '\n';

  //s - n*n + n  < n
  //s < n * n


  return 0;
}