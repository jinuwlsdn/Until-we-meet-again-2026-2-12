#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

vector<int> v[101];
vector<int> result[101];


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //1389
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  int n,m;

  cin >> n >> m;

  for(int i = 0 ; i < m ;  ++i){
    int p,q;
    cin >> p >> q;

    v[p].push_back(q);
    v[q].push_back(p);
  }
  

  
  for(int i=1 ; i<=n; ++i){
    queue<pair<int, int>> q;
    
    
    bool visited[101];
    memset(visited, false, sizeof(visited));
    q.push({i,0});
    visited[i] = true;

    while(!q.empty()){

      int person = q.front().first;
      int depth = q.front().second;

      q.pop();

      for(int next : v[person]){

        if(!visited[next]){
          visited[next] =true;
          q.push({next, depth+1});
          result[i].push_back(depth);
        }
      }

    }

  }

  int min_value  =  5000000;
  int min_person = 0;
  for(int i = 1; i <= n ; ++i){
    int sum = 0;

    for(int value : result[i]){
      sum += value;
    }

    if(min_value > sum){
      min_value = sum;
      min_person = i;
    }
  }


  cout << min_person << '\n';



  return 0;
}