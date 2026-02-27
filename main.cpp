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

  
  //3273

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  int n;
  cin >> n;
  vector<int> v(n);

  for(int i = 0 ; i < n ; ++i){
    cin >> v[i];
  }

  int x;
  cin >> x;

  sort(v.begin(), v.end());

  int cnt = 0;

  int start =0;
  int end = n-1;

  while(start < end){
    int sum = v[start] + v[end];

    if(sum == x){
      cnt++;
      start ++;
    }

    if(sum > x){
      end--;
    }
    else if(sum < x){
      start++;
    }




  }


  cout << cnt << '\n';


  
  return 0;
}