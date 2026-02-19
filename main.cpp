#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>




using namespace std;

const int MAX = 1e5;

vector<int> graph[MAX+1];
bool visited[MAX+1];
int parents[MAX+1];
int n;


void dfs(int k){
  //k를 넣고 k의 부모를 찾아올라가서 반환하면 된다.

  
  visited[k] = true;

  for(int next : graph[k]){
    if(!visited[next]){
      parents[next] = k;
      dfs(next);
    }
  }


}





int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //11725

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점
  //1. 이차원 배열로 서로 연결해서 부모를 찾는 방법으로 접근해야할 것 같다.
  //그리고 당연히 방문한 노드는 다시 방문하지 않는다. 그리고 2번노드 부터 출력한다 
  //탐색하려고 하는 대상 노드를 p라고 했을 때 graph[p][k] == 1 (k는 1부터 n) 
  //result[k] = p , dfs(k) 끝나면 for문으로 1부터 n까지 출력.

  //2. 시간복잡도 O(V+E)  트리니까 정점은 N , E는 2*N 총 3*N 1억보다 작다.

  //3. 관계를 나타낼 때에는 이차원배열로 표현 , bool visited <- 1차원배열.
  

  

  cin >> n;

  for(int i = 0 ; i < n-1 ; ++i){

    //여기서 2번노드부터니까 i는 1부터시작.

    int p,q;
    cin >> p >> q;

    graph[p].push_back(q);
    graph[q].push_back(p);
  }

  dfs(1);

  for(int i = 2 ; i <=n; ++i){
    cout << parents[i] << '\n';
  }

  

  return 0;
}