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

  //2110
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 생각좀 해보자

  int n,c;

  cin >> n >> c;

  vector<int> house(n);

  for(int i = 0 ; i < n ; ++i){
    cin >> house[i];
  }

  sort(house.begin(), house.end());

  int left = 0 , right = house[n-1] - house[0];


  int result  = 0 ;

  while(left<=right){
    int mid = (left+right) / 2;

    int count = 1;

    int next_house = house[0];
    for(int j = 1; j<n; ++j){
      if(house[j] - next_house >= mid){
        count++;
        next_house = house[j];
      }
    }

    if(count >= c){
      result = mid;
      left = mid+1;
    }
    else{
      right = mid - 1;
    }

  }



  cout << result << '\n';



 

  return 0;
}