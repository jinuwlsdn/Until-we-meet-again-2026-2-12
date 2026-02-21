#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 20;

int soccer[MAX+1][MAX+1];
bool visited[MAX+1];
int n; 
int min_gap = 1e9;


void dfs(int depth, int idx){

  if(depth == n/2){
    
    int s_team =0;
    int l_team =0;

    for(int i = 1;  i<=n ; ++i){
      for(int j = 1; j <=n ; ++j){

        if(visited[i] && visited[j]){
          //둘 다 같은 팀 true를 s팀이라고 하자
          s_team += soccer[i][j];
        }
        else if(!visited[i] && !visited[j]){
          //둘 다 같은 팀 false를 l팀이라고 하자
          l_team += soccer[i][j];
        }

      }
    }

    int min_value = abs(s_team - l_team);
    min_gap = min(min_gap, min_value);
    return;
  }



  for(int i = idx  ; i <= n; ++i){

    if(!visited[i]){
      //방문 X 
      visited[i] = true;
      dfs(depth+1, i+1);
      visited[i] = false;
    }
  }
}


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //14889

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. true , false로 팀 두개를 만든 다음에 depth ==  n/2이면 그 때 true false 값을 통해서
  //팀의 능력치를 계산한다.

  //2. ..? N이 20이고 만드는 팀의 구성원은 N/2 최대가 10이니까 중복을 허용 X O(N!) N이 10이므로 가능

  //3. 값을 저장할 이차원배열 , 또한 중복을 허용하지 않으므로 bool 1차원배열

  //4. dfs의 종료조건을 설정해야한다.


  
  cin >> n;


  //i가 세로 j가 가로

  for(int i = 1 ; i <= n ;  ++i){
    for(int j = 1 ; j <= n ;  ++j){
      cin >> soccer[i][j];
    }
  }


  dfs(0,1);

  cout << min_gap << '\n';

  

  
 
  
  return 0;
}