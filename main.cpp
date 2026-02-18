#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <deque>


using namespace std;

const int MAX = 100000;
int graph[MAX+1];
bool visited[MAX+1];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //13549

  //1. 순간이동하는데 시간은 필요없긴하지 음 기본적인 틀은 똑같은데 0초후니까 순간이동 하는경우엔
  //++을 하지 않으면 될것같다.
  //우선순위 큐? / K에 먼저 도착한 경우의 수가 반드시 seconds가 최소인 것은 아님.
  // ex) N이 1 K가 2라고 했을때 x+1 , 2*x 둘 다 2에 도착하지만 x+1은 1이고 2*x는 0의 값을 가진다.

  //2 시간복잡도 숨바꼭질 처음문제처럼 나오겠다 O(V+E) V는 십만 E는 간선이 3개니까 삼십만 총 사십만
  // OK
  //3. int 배열 , bool visited , queue 자료구조 

  //4 visited 잘 체크하기.

  int n,k;

  cin >> n >> k;

  int seconds = 0;

  deque<int> dq;

  dq.push_back(n); // 초기 위치를 넣어준다.

  visited[n] = true; // 초기 위치에 다시 오지않는다.

  while(!dq.empty()){
    int x = dq.front();

    dq.pop_front(); // pop을 할때 무엇을 할지 몰라서

    if(x==k){
      seconds = graph[x];
      break;
    }

    for(int next_pos : {2*x, x-1, x+1}){
      if(0 <= next_pos && next_pos <= MAX && !visited[next_pos]){
        if(next_pos == 2*x){
          // 가중치가 
          visited[next_pos] = true;
          dq.push_front(next_pos);
          graph[next_pos] = graph[x];
        }
        else{

          // x+1, x-1는 뒤에 넣는다.
          visited[next_pos] = true;
          dq.push_back(next_pos);
          graph[next_pos] = graph[x] + 1;
        }

      }
    }

  }

  
  cout << seconds << '\n';


  return 0;
}