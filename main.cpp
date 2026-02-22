#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n,m;

vector<int> friends[2001];
bool visited[2001];
int result = 0;

void recurse(int first, int depth){


  visited[first] = true;

  if(depth == 4){
    result = 1;
    return;
  }

  for(int next : friends[first]){
    if(!visited[next]){
      recurse(next, depth+1);
      visited[next] = false;
    }
  }

  visited[first] = false;
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //13023 다음에 14719
  

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. A->B->C->D->E 같은 순서로 만족하는 case가 있으면 1을 리턴 없으면
  //0 리턴하면 된다. 백트래킹

  //2. 시간복잡도는 O(V+E) dfs로 경우의수를 찾다가 탐색 종료하면 될 것같다.
  //V는 2000이고 가짓수는 2000*2000 n^2  / 4 000 000 2억 이하 

  //3. visited 함수와 두 친구 사이의 관계를 나타내기 위해 2차원배열

  cin >> n >> m;

  for(int i = 0 ; i < m ;++i){
    int p,q;

    cin >> p >> q;

    friends[p].push_back(q);
    friends[q].push_back(p);
  }

  
  for(int i = 0 ; i < n; ++i){
    
    recurse(i,0);

    if(result == 1) break;

  }
  

  cout << result << '\n';


  
  return 0;
}