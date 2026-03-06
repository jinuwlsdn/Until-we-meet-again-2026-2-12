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

  
  
  //7795
  //16234
  //2343
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  int T;
  cin >> T;

  while(T--){

    int n,m;

    cin >> n >> m;

    vector<int> a;
    vector<int> b;
    

    for(int i =0  ; i <n ; ++i){
      int k;
      cin >> k;
      a.push_back(k);
    }
    for(int i =0  ; i <m ; ++i){
      int k;
      cin >> k;
      b.push_back(k);
    }
    sort(b.begin(), b.end());

    int count = 0;
    for(int i =0  ; i <n ; ++i){
      


      int left = 0 , right = m;
      while(left+1 < right){
        int mid = (left+right)/2;

        if(b[mid] < a[i]){
          left = mid;
        }
        else right = mid;
      }

      count += left;
      if(a[i] > b[left]) count++;
      //1 3 6 
      //8을 탐색해보는데 left가 이 경우엔 2다
      //근데 86 83 81 3개이므로 count++ 해준다
    }
    
    cout << count << '\n';

  }

  

  return 0;
}