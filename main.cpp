#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>


using namespace std;

const int MAX = 100000;

int graph[MAX+1];
bool visited[MAX+1];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1697 

  //1. 이게 왜 bfs문제임? -> 탐색을 한다고 했을 때 선택지가 x-1 x+1 , 2*x
  //그렇다면 첫번째 위치에서 나올 수 있는 가짓수가 3가지고 그래프로 연결해본다고 했을때  한 자식한테
  //나오는 가짓수가 3개고 그러면 그렇게 각 정점을 돌아다니면서 위치가 동생 위치일 때 종료하면됨.
  

  //2. O(V+E) 만들어진 정점들은 최대 100000 간선들은 하나에 최대가 3이니까 3*100000 그래도 2초보단 작다
  

  //3. 일차원배열을 만들어서 방문했는지 안했는지 , bfs니까 queue FIFO 100000이니까 int로 잡아도 된다.

  
  int n,k;

  cin >> n >> k;

  queue<int> q;


  //graph 배열에서 각 배열에다가 초를 기입하면 된다. 그 후에 ++한 값으로 저장하면되니까.

  q.push(n);


  int seconds = 0;
  visited[n] = true;

  //이떄 q.empty()는 필요가있나?다 탐색하는데 없을 수가 없잖아.
  while(!q.empty()){
    int next_x = q.front();

    q.pop();

    


    //위치가 맞아야지
    if(next_x == k){
      seconds = graph[next_x];

      //cout << next_x << '\n';

      break;
    }
    

    //값이 맞고 방문을 X 
    if(0<= next_x + 1 && next_x + 1 <= MAX  && !visited[next_x+1]){
      q.push(next_x+1);
      graph[next_x+1] = graph[next_x] + 1;
      visited[next_x+1] = true;
      
    }
    if(0<= next_x - 1 && next_x - 1 <= MAX  && !visited[next_x-1]){
      q.push(next_x-1);
      graph[next_x-1] = graph[next_x] + 1;
      visited[next_x-1] = true;
    }
    if(0<= 2 * next_x && 2 * next_x  <= MAX  && !visited[2*next_x]){
      q.push(2 * next_x);
      graph[2 * next_x] = graph[next_x] + 1;
      visited[2 * next_x] = true;
    }

    
  }


  cout << seconds << '\n';




  




  return 0;
}