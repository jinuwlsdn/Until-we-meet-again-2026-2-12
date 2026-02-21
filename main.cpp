#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


const int MAX = 100;
int people[MAX+1][MAX+1];
bool visited[MAX+1];
int n;
int t1, t2;

int value  = -1;

void dfs(int depth, int num){

  if(num == t2){
    value = depth;
    return;
  }


  for(int i = 1; i <= n; ++i){
    if(people[num][i] && !visited[i]){
      visited[i] = true;
      dfs(depth+1, i);
      visited[i] = false;
    }
  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //2644

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 촌 계산을 하면 된다. dfs로 t1을 받아서 그 t1 t2가 만날때까지 dfs를 하면 정답을
  //찾을 수 있다. 이 때 정답은 depth값이 된다.

  //2. 시간복잡도는 O(V+E) : V는 100 E는 간선이 2개니까 2 * 100 300은 1억보다 작다.

  //3. 두 부모 자식간의 관계를 나타내기 위해서 이차원배열을 사용, bool visited(갔다가 다시 돌아오면 안되기 때문에)

  //4. bool visited , 종료조건 

  cin >> n;

  

  cin >> t1 >> t2;

  int m;

  cin >> m;

  for(int i =0 ; i  < m;  ++i){

    int p,q;

    cin >> p >> q;

    people[p][q] = 1;
    people[q][p] = 1;

  }

  dfs(0,t1);

 
  cout << value << '\n';

  
 
  
  return 0;
}