#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

const int MAX = 1e9;




//int depth[MAX+1];

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //16953
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //10억 = 10^9

  int a,b;

  cin >> a >> b;

  queue<pair<long long, int>> q;

  set<long long> visited;

  q.push({a,1});
  visited.insert(a);

  //dfs를 쓰면 최솟값이 아닐 수 가 있다 dfs는 한 곳만 파기때문에 
  //그래서 퍼져나가는 원하는 수 b에 먼저 도달하는 친구가 있다면 그 친구가 최솟값이다.
  //근데 dfs는 그럴 것이라는 보장이 없다.


  int min_value = -1;
  while(!q.empty()){

    long long curr = q.front().first;
    int dist = q.front().second;

    

    if(curr == b){
      min_value = dist;
      break;
    }

    q.pop();

    if(!visited.count(curr * 2) && curr * 2 <= b){
      q.push({curr * 2 , dist+1});
      visited.insert(curr * 2);
    }
    long long next_num = curr*10 + 1;
    if(next_num > MAX) continue;
    if(!visited.count(next_num) && next_num <= b){
      q.push({next_num, dist+1});
      visited.insert(next_num);
    }
  }

  cout << min_value << '\n';


  return 0;
}