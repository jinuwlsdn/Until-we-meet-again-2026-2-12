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

  
  //14719

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //1. 이차원배열을 통해서 만약 블럭이 1이라면 그 세로선을 통해 가로로 탐색하면서
  //다시 1이 되는 블럭을 찾고 그 블럭까지의 거리를 cnt에 추가한다 그리고 탐색한 그 블럭들은
  //다시 중첩이 되면 안되기 때문에 1의 값을 다시 넣어준다.

  //2. n^2 모든 블럭들을 다 순회하고 그 블럭중에서 다시 가로로 탐색한다고 가정했을때 n번 더곱한다
  //n^3

  //3 이차원배열



  int h,w;

  cin >> h>>w;

  int cnt=0;

  vector<int> height(w);

  for(int i = 0 ; i < w ; ++i){
    cin >> height[i];
  }


  for(int i = 1; i<w-1; ++i){

    int left_h =0;
    int right_h =0;

    for(int j = 0 ; j<i; ++j){
      left_h = max(left_h, height[j]);
    }
    for(int j = i; j<w; ++j){
      right_h = max(right_h, height[j]);
    }

    int min_h =0;

    min_h = min(left_h, right_h);

    if(min_h > height[i]){
      cnt += (min_h - height[i]);
    }

  }
  
  cout << cnt << '\n';



  
  return 0;
}