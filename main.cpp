#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

vector<int> a;
vector<int> b;


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //11663
  //16234
  
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 입력 받고 점의 좌표를 정렬한다 그리고 이분탐색으로 접근하는데 index로 각 선분마다
  //몇개 점이있는지 출력한다

  //2. nlogn 100000*20 <- 정렬했을때 , 이분탐색했을때 같다 100000*20 * 2 4백만 
  //1억보다 작다.

  //3. vector<int> 사용

  int n,m;

  cin >> n >> m;

  vector<int> dots;
  for(int i = 0 ; i < n ; ++i){
    int k;
    cin >> k;
    dots.push_back(k);
  }

  sort(dots.begin(), dots.end());
  for(int i = 0 ; i < m ; ++i){
    int st , en;
    cin >> st >> en;

    int count = 0, left = 0 , right = n-1;


    while(left<=right){
      int mid = (left+right) / 2;


    
      if(dots[mid] >= st){
        right = mid - 1;
      }
      else{
        left = mid + 1;
      }

    }
    int underIndex = left;
    left = 0 , right = n-1;

    while(left<=right){
      int mid = (left+right) / 2;

      if(dots[mid] > en){
        right = mid - 1;
      }
      else{
        left = mid + 1;
      }
    }
    int overIndex = right+ 1;


    count = overIndex - underIndex;
    cout << count << '\n';
  }



  return 0;
}