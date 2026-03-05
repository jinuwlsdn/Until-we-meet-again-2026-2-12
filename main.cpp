#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

const int MAX  = 100;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int tomato[MAX+1][MAX+1][MAX+1];


struct Location{
  int h, y , x;
};



int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //1 문제에서 시키는대로 구현만 하면 될 것 같다 근데 한 중심으로
  //퍼지는 부분이니까 bfs를 사용하면 될 것 같고 그래프에다가 값을 넣어서 !q.empty() 될때까지
  //작업을 시행한다 그리고 그래프에서 값을 탐색하면서 만약 0이 있다면 -1이고  모두 익어있으면
  //0을 출력하고 아니면 최소날짜기때문에 그래프중에서 가장 높은 값을 선택하면된다.
  //그래프 탐색하면서 값을 줄때 현재값 + 1을 주면 다음날로 저장이 된다.

  //2. O(V+E) 1000 * 1000 + 4 * 1000 * 1000 1억보다 작다.

  //3. 이차원배열 및 visited
  // 1000 * 1000 * 4 = 4000000 백만바이트 4mb 충분하다

  //visited 안하는거


  

  
 

  return 0;
}