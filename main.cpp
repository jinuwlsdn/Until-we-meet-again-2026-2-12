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

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //2644

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  int n;

  cin >> n;

  int t1 , t2;

  cin >> t1 >> t2;

  int m;

  cin >> m;
  

  for(int i = 0 ; i < m ;  ++i){
    int p , q;
    cin >> p >> q;

    people[p][q] = 1;
    people[q][p] = 1;
  }

  queue<pair<int , int>> q;

  int value = -1;
  q.push({t1,0});
  while(!q.empty()){
    
    int f = q.front().first;
    int s = q.front().second;
    

    q.pop();

    if(f == t2){
      value = s;
      break;
    }

    for(int i = 1 ; i <= n ; ++i){
      if(people[f][i] && !visited[i]){
        //방문 X
        visited[i] = true;
        q.push({i,s+1});
      }
    }


  }


  cout << value << '\n';
 
  
  return 0;
}