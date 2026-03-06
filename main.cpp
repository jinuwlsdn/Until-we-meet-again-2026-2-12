#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

vector<int> num;
int n;

int search_n(int target){

  int left = 0, right = n-1;

  while(left <= right){
    
    int mid = (left+right)/2;

    if(num[mid] == target){
      return 1;
    }
    else if(num[mid] > target){
      right = mid -1;
    }
    else{
      //num[mid] < target
      left = mid + 1;
    }

    //12345
  }


  return 0;
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //1920
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //1. n개의 정수가 주어졌을때 x라는 정수가 존재하나 안하나 이분탐색으로 찾으면 될 것 같다.

  //2. M의 최댓값이 십만이고 N도 십만이니까 브루트포스로 만약 하나하나 다 찾아본다면 N^2 1억을 훨씬 넘긴다.
  //따라서 이분탐색의 방법으로 찾아야한다.

  //3. vector를 사용하자.

  

  cin >> n;

  

  for(int i = 0 ; i < n ; ++i){
    int k;
    cin >> k;
    num.push_back(k);
  }

  int m;

  cin >> m;

  vector<int> search_num;

  for(int i = 0 ; i < m ; ++i){
    int k;
    cin >> k;
    search_num.push_back(k);
  }

  //1 2 3 4 5
  //정렬을 하고 left right 값을 받아온 후 index로 조정을한다
  //만약 탐색한 값이 작다면 올리고 크면 내린다 같으면 탐색종료

  
  sort(num.begin(), num.end());

  for(int i = 0 ; i < m ; ++i){
    int k = search_num[i];

    int check = search_n(k);

    cout << check << '\n';
  }








  return 0;
}