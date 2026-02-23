#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int num[11];
bool visited[11];
int n,k;
set<string> s;

void dfs(string line, int depth){
  if(depth == k){

    s.insert(line);
    return;
  }

  //1 2 3 13 21
  for(int i= 0 ; i < n ; ++i){
    if(!visited[i]){
      
      visited[i] = true;
      dfs(line + to_string(num[i]),depth+1);
      visited[i] = false;
    }
  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //14719
  //5568
  

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  
  cin >> n>>k;
  for(int i = 0 ; i < n ; ++i){
    cin >> num[i];
  }

 
  dfs("", 0);
  cout << s.size() << '\n';
  
  return 0;
}