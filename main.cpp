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


  //5585
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  int k;
  cin >> k;
  int pay = 1000 - k;

  int change = 0;

  for(int i = 0 ; i < 6 ; ++i){
    if(pay / yen[i] != 0 ){
      //동전으로 바꿀 수 있다.

      change += pay/yen[i];

      pay = pay % yen[i];
    }
  }


  cout << change << '\n'


  return 0;
}